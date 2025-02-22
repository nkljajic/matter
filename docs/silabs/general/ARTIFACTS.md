# Matter Software Artifacts

This page provides links to pre-built software image "artifacts" that can be
used to set up the Matter Demo for the Thread and Wi-Fi use cases.

## Matter Hub Raspberry Pi Image

The Matter Hub image is intended to be flashed onto an SD card for a Raspberry
Pi. The Matter Hub Image provides both an Open Thread Border Router and the
Matter chip-tool. Note the image is ~10GB in size so depending on your internet
connection this download may take some time. Start the Matter Hub Raspberry Pi
image download here:

https://www.silabs.com/documents/public/software/SilabsMatterPi_2.0.0-1.1.zip

## Radio Co-Processor (RCP) Images

The Radio Co-Processor firmware is used to turn an EFR into an RCP that can be
used with a Raspberry Pi to allow the Raspberry Pi's Open Thread Border Router
to access the Thread network. Radio Co-Processor (RCP) images are available in
the Assets section of this page:

https://github.com/SiliconLabs/matter/releases/tag/v2.1.0-1.1

## Matter Accessory Device Images

The Matter Accessory Device Images are used to turn an EFR into a Matter device.
These are pre-built binary images for the Matter Demo. Matter Accessory Device
Images are located in the Assets section of this page:

https://github.com/SiliconLabs/matter/releases/tag/v2.1.0-1.1

For Matter over Thread, 3 different types of images are provided:

1. **Standard**: Includes all code including enabling the LCD for a QR Code that can be used for commissioning.
2. **Release**: A smaller image size with reduced functionality, including removal of the LCD support, thus no QR Code.
3. **Sleepy**: A sleepy device image for improved energy efficiency and running on battery power.

## Matter Bootloader Binaries

If you are using the OTA functionality and especially if you are using an
EFR32MG2x device, you will need to flash a bootloader binary on your device along
with the application image. Bootloader binaries for all of the Matter supported
devices are available here:

https://github.com/SiliconLabs/matter/releases/tag/v2.1.0-1.1

## RS9116 Firmware

The RS9116 firmware is used to update the RS9116 - it can be found in the
repository you have cloned, at the following relative path from the `/matter`
directory, `./third_party/silabs/wiseconnect-wifi-bt-sdk/firmware`

## SiWx917 Firmware

> **Note**: SiWx917 firmware is only available to Alpha customers. Contact Silicon Labs support to obtain the WiseMCU SDK and install it as per the instructions on the [Software Requirements page](./SOFTWARE_REQUIREMENTS.md).

The SiWx917 firmware is used to update the SiWx917 device connectivity firmware. It can be found in the
repository you have cloned, at the following relative path from the `/matter`
directory, `./third_party/silabs/wisemcu-wifi-bt-sdk/connectivity_firmware`

## SiWx917 SoC Configuration Files for Flashing the Matter Application

In order to flash the Matter Application on the SiWx917 SoC, the Ozone Debugger must
be configured for the SiWx917 SoC device by following the instructions on the [Ozone Environment Setup for SiWx917 SoC page](../wifi/SiWx917_Enablement_For_Ozone.md).

The **JLinkDevices.xml** and **ELF** files referenced in the instructions may be found 
in the Assets section of this page:

https://github.com/SiliconLabs/matter/releases/tag/v2.1.0-1.1
