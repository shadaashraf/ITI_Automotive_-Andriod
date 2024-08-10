# Yocto Recipe for Printing a Message

## Overview

This guide walks you through creating a Yocto recipe that prints a simple message during the build process. We’ll cover setting up the recipe, building it, and verifying the output.

## Prerequisites

- Yocto Project environment set up.
- Basic familiarity with Yocto and BitBake.
- Your Yocto project should be configured correctly and buildable.

## Steps

### 1. Set Up Your Environment

1. **Navigate to Your Yocto Directory**:

   ```sh
   cd ~/yocto
   ```

2. **Source the Environment Setup Script**:

   Ensure your Yocto environment is set up correctly by sourcing the environment setup script. This is usually done with:

   ```sh
   source oe-init-build-env
   ```

   This will set up the necessary environment variables and directories for your Yocto build.

### 2. Create the `meta-iti` Layer

1. **Create the `meta-iti` Layer Directory**:

   ```sh
   mkdir -p meta-iti
   ```
![Screenshot from 2024-08-10 22-40-17](https://github.com/user-attachments/assets/a17da15d-10c8-49c0-9cf3-b9c8c72f4351)

2. **Navigate to the Layer Directory**:

   ```sh
   cd meta-iti
   ```

3. **Create the Recipe Directory**:

   ```sh
   mkdir -p my-recipes/recipe
   cd my-recipes/recipe
   ```
![Screenshot from 2024-08-10 22-47-27](https://github.com/user-attachments/assets/0fa2a6b0-c7b2-43ec-8719-86a518fc5f1b)

### 3. Create the Recipe File

1. **Create a Recipe File**:

   Create a file named `app1_1.0.bb` in `meta-iti/my-recipes/recipe/` with the following content:

   ```sh
   SUMMARY = "A recipe to print a simple message to the terminal"
   DESCRIPTION = "This recipe prints a plain message during the build process"
   LICENSE = "MIT"

   do_configure() {
       echo "Hello, this is a simple message from your Yocto recipe!"
   }

   do_install() {
       # No installation needed for this recipe
       :
   }
   ```

2. **Ensure Your Layer Configuration**:

   Verify that your `layer.conf` (located in `meta-iti/conf/`) includes the path to your recipe:

   ```sh
   BBPATH .= ":${LAYERDIR}"

   BBFILES += "${LAYERDIR}/recipes-*/*/*.bb \
               ${LAYERDIR}/recipes-*/*/*.bbappend \
               ${LAYERDIR}/my-recipes/*/*.bb"

   BBFILE_COLLECTIONS += "meta-iti"
   BBFILE_PATTERN_meta-iti = "^${LAYERDIR}/"
   BBFILE_PRIORITY_meta-iti = "6"

   LAYERDEPENDS_meta-iti = "core"
   LAYERSERIES_COMPAT_meta-iti = "kirkstone"
   ```

   
![Screenshot from 2024-08-11 01-05-51](https://github.com/user-attachments/assets/ad464d99-a8ee-4583-a62e-a4f505ea5861)


### 4. Modify `bblayers.conf`

1. **Navigate to the `conf` Directory**:

   ```sh
   cd ~/yocto/poky/build/conf
   ```

2. **Edit `bblayers.conf`**:

   Open `conf/bblayers.conf` in your favorite text editor and add your new layer to the `BBLAYERS` variable:

![Screenshot from 2024-08-10 23-05-14](https://github.com/user-attachments/assets/3c02a899-f225-4e97-9f17-0eea5060ec8e)


   Save and close the file.

### 5. Build the Recipe

1. **Clean the Recipe State** (optional but recommended to ensure a fresh build):

   ```sh
   bitbake -c cleanall app1
   ```

2. **Build the Recipe**:

   ```sh
   bitbake app1
   ```

 
   ![Screenshot from 2024-08-11 00-08-14](https://github.com/user-attachments/assets/bc548fb6-b321-4088-8ad0-e40e72c43233)


### 6. Locate and View the Logs

1. **Navigate to the Recipe’s Work Directory**:

   ```sh
   cd ~/yocto/poky/build/tmp/work/core2-64-poky-linux/app1/1.0-r0/temp
   ```

   Here, `core2-64-poky-linux` is your target machine, and `1.0-r0` is the version and release number of your recipe.

2. **View the Logs**:

   ```sh
   ls log.*
   cat log.do_configure
   ```

### Example Output

In `log.do_configure`, you should see:

![Screenshot from 2024-08-11 00-25-06](https://github.com/user-attachments/assets/639b91a3-57f0-47a8-9bfd-c7de0d201f59)


## Troubleshooting

- **Recipe Not Found**: Verify `BBFILES` in `layer.conf` and ensure the recipe file is correctly placed.
- **No Output**: Check that the correct task (`do_configure`) is running and verify its log file.

---

Feel free to adjust any details to better fit your specific setup or preferences!

