/******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

/**
 * @defgroup group_translator
 * @brief Translate between matter groups ans unify groups.
 *
 * The purpose of the group translator is to translate Matter group into Unify groups
 *
 * @{
 */

#ifndef GROUP_TRANSLATOR_HPP
#define GROUP_TRANSLATOR_HPP

#include <optional>
#include <set>

#include "matter.h"
#include "matter_data_storage.hpp"
#include "uic_mqtt.h"
#include <string>
#include <ostream>

namespace unify::matter_bridge {

using unify_group_t = uint16_t;

/**
 * @brief Group Translator
 * The role of the group translator is to translate between Unify Group Ids
 * and matter group ID's
 */
class group_translator
{
public:
    struct matter_group
    {
        chip::GroupId group;
        chip::FabricIndex fabric_index;

        bool operator<(const matter_group & b) const { return group < b.group; }
    };

    group_translator(matter_data_storage & data_storage) : last_allocated_group(1), m_matter_data_storage(data_storage) {}
    virtual ~group_translator() {}

    virtual std::optional<unify_group_t> get_unify_group(const matter_group & group);

    /**
     * @brief Register a new matter group
     *
     * This function allocates a new unify group to match with the matter group number.
     *
     * @param group
     * @return true
     * @return false
     */
    virtual bool add_matter_group(const matter_group & group);

    /**
     * @brief Remove a created group map
     *
     * @param group
     */
    virtual void remove_matter_group(const matter_group & group);

    /**
     * @brief Register a created unify group
     *
     * This is used to ensure that we do not allocate unify
     * groups which are already in use
     *
     * @param group
     */
    void register_unify_group(const unify_group_t & group);

    /**
     * @brief Registers a mqtt subscription callback for
     *        "ucl/by-group/#" topic
     */
    void register_unify_group_mqtt_message()
    {
        std::string topic_by_group = "ucl/by-group/#";
        uic_mqtt_subscribe_ex(topic_by_group.c_str(), group_translator::on_mqtt_message_c_cb, this);
    }
    /**
     * @brief Display group mapping that depicts which matter groups correspond to which unify groups
     * @param std::ostream
     */
    void display_group_mapping(std::ostream &os);

private:
    unify_group_t last_allocated_group;
    std::set<unify_group_t> allocated_unify_groups;
    matter_data_storage & m_matter_data_storage;
    void on_mqtt_message_cb(const char * topic, const char * message, const size_t message_length);
    static void on_mqtt_message_c_cb(const char * topic, const char * message, const size_t message_length, void * user)
    {
        group_translator * instance = static_cast<group_translator *>(user);
        if (instance)
        {
            instance->on_mqtt_message_cb(topic, message, message_length);
        }
    }
 };

} // namespace unify::matter_bridge

#endif // GROUP_TRANSLATOR_HPP
/** @} end group_translator */
