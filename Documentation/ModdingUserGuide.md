# Rooftops and Alleys Modding User Guide
## Requirements
**Modkit Version: 1.0 ->** `Plugin/RNAModkit`  
**Base Game Release Version:** INSERT HERE  
**Unreal Version: 5.4**  
**Modio Unreal Version: 2026.6 ->**  [https://github.com/modio/modio-ue/releases/tag/v2026.6](https://github.com/modio/modio-ue/releases/tag/v2026.6)  
**ModioUGC Version: 2026.3 ->** [https://github.com/modio/modio-ue-modiougc/releases/tag/v2026.6](https://github.com/modio/modio-ue-modiougc/releases/tag/v2026.6)

The official Rooftops and Alleys modding support allows the following modifications:
- Add Objects for the level editor
- Add new Body Parts to the character
- Change the model and/or animations of the pigeon
- Add whole Unreal levels

## Setup
- Download Unreal Engine 5.4
- Create a new Blank C++ project named “RooftopsandAlleys”
- Download the game’s Unreal Releases folder, extract it, and add it to your new project in a folder called “Releases” next to the .uproject file of your new project. It should look like this: `Game\Releases\BaseGamerelease\Windows`
- Download the RNAModkit plugin and add it to your new project. If you don’t have a “Plugin” folder, create one next to the “Releases” folder and put the plugin there.
- Download the Modio core and ModioUGC plugins and add them to your new project

## Create a Mod
Mods for Rooftops and Alleys are packaged in the form of DLC Plugins. Follow these steps to create a new mod. 

First, create a new Content Plugin:
- Open your project in the Unreal Editor
- At the top of the editor window, click on the [Mod.io](http://mod.io) widget  
![](Images/OpeningModioWidget.png)
- Select “Create Mods” to create a new plugin  
![](Images/ModioWidgetCreateMod.png)
- In the New Mod window, fill in the different information with at least the Mod Name, Author, and Description.
- Click “Create Mod Package”

Now, time to create the content of your mod:
- Open the Content Browser in the Unreal Editor
- Go to `Mods/YourPluginName` content folder
- First, edit the UUGC\_Metadata file like this:  
![](Images/UGCMetadata.png)
- Now, you can create your mod content. To do so, you can use the various **templates located in the RNAModkit plugin**. You will find:
  - Skeletons of the body and the head of the player character
  - Animation Blueprint templates for the pigeon
  - And a Skysphere for your mod Levels. You need to use a skysphere for the Switch 2 compatibility of your level: *On mobile the SkyAtmosphere component needs a mesh with a material tagged as IsSky and using the SkyAtmosphere nodes to visualize the Atmosphere.*  
  You can use a different Skysphere than the one provided in the modkit if you want. [https://forums.unrealengine.com/t/help-completely-lost-with-the-message-on-mobile-skyatmosphere-needs-a-mesh-tagged-issky/252845](https://forums.unrealengine.com/t/help-completely-lost-with-the-message-on-mobile-skyatmosphere-needs-a-mesh-tagged-issky/252845)
- Once you have created the content of your mod, you need to reference it in one or more Data Assets:  
  In your mod plugin, create a new Data Asset of the right type for each element added to the game by your mod. There are 4 types of data assets in the Modkit plugin that you must choose from (One mod Plugin can contain multiple Data Assets):
  - **Mod Item Definition** (for a new level editor element)
  - **Mod Body Part Definition** (for a new character body part)
  - **Mod Pigeon Definition** (for changing the pigeon model)
  - **Mod Level Definition** (for a new Level)  

> **/!\\ The game only loads content through these Data Assets. You MUST include them for your mod to work. /!\\**

- Now that you have your Data Asset(s), you need to reference the mod content inside like following: 
- For a level editor Item, use a Mod Item Definition as follows:
  - Item Name _(Name)_ → Name of the New Item
  - Mesh _(StaticMesh)_ → Static Mesh of the New Item
  - Thumbnail _(Texture2D)_ → Icon of the Item for the menu
  - Materials _(Array of Materials)_ → Materials applied to the static mesh (Optional)
  - Category _(Name)_ → Category of the Item: **_“Modding”_**
- For a Head, Torso, Bottom, or Shoes body part, use a Mod Body Part Definition as follows:
  - Item Name _(Name)_ → Name of the New Item
  - Thumbnail _(Texture2D)_ → Icon of the Item for the menu
  - BodyPart _(List)_ → Select the Type of this body part
  - Skeletal Mesh _(SkeletalMesh)_ → Skeletal Mesh of the new body part
  - Feathers _(Integer)_ → Cost In feathers of the item (Optional)
  - **Leave all other fields empty**
- For a Backpack, Headwear, or Pigeon Accessory, use a Mod Body Part Definition as follows:
  - Item Name _(Name)_ → Name of the New Item
  - Thumbnail _(Texture2D)_ → Icon of the Item for the menu
  - BodyPart _(List)_ → Select the Type of this body part
  - Static Mesh _(StaticMesh)_ → StaticMesh of the new Accessory
  - Feathers _(Integer)_ → Cost In feathers of the item (Optional)
  - **Leave all other fields empty**
- For a Trail, use a Mod Body Part Definition as follows:
  - Item Name _(Name)_ → Name of the New Item
  - Thumbnail _(Texture2D)_ → Icon of the Item for the menu
  - BodyPart _(List)_ → Select the Type of this body part
  - Feathers _(Integer)_ → Cost In feathers of the item (Optional)
  - Niagara _(NiagaraSystem)_ → New Trail effect
  - **Leave all other fields empty**
- For a Pigeon Skin, use a Mod Body Part Definition as follows:
  - Item Name _(Name)_ → Name of the New Item
  - Thumbnail _(Texture2D)_ → Icon of the Item for the customization menu
  - BodyPart _(List)_ → Select the Type of this body part
  - Feathers _(Integer)_ → Cost In feathers of the item (Optional)
  - Pigeon Skin _(Material)_ → New pigeon skin material
  - **Leave all other fields empty**
- For a full model of the pigeon, use a Mod Pigeon Definition as follows:
  - Name _(Name)_ → Name of the New Model
  - Thumbnail _(Texture2D)_ → Icon for the customization menu
  - Skeletal Mesh _(SkeletalMesh)_ → Skeletal Mesh of the model
  - ABP\_Default _(AnimationBlueprint)_ → Principal Animation Blueprint
  - ABP\_Pickup _(AnimationBlueprint)_ → Pickup Animation Blueprint
  - ABP\_NPC _(AnimationBlueprint)_ → Animation Blueprint played in the Menus
  - AM Barrel Roll R _(AnimationMontage)_ → Animation played on a Right Barrel Roll
  - AM Barrel Roll L _(AnimationMontage)_ → Animation played on a Left Barrell Roll
  - On top of those elements, your mod needs to contain: The **Skeleton** of your model, the **Physics Asset** of your model, and the various **Animation Sequences** used in your Animation Blueprints and Animation Montages, such as Diving, Flying, Standing, and Walking
- For a level, use a Mod Level Definition as follows:
  - Level Name _(Name)_ → Name of the New Level
  - Level _(UWorld)_ → Actual Unreal Level
  - Preview Image _(Texture2D)_ → In-game preview of the level
  - On top of those elements, your mod needs to contain **all the material and Static Meshes** used in the level

> **/!\\ To prevent the execution of outside code, the mod levels are sanitized, so we highly recommend that you prevent adding any Blueprint Class to your Mod Level and only use Static Meshes. /!\\**

Once you are done, compress your mod plugin files in a **ZIP** archive.\
The archive must not include the “Saved” directory of your plugin. The _“.uplugin”_ file must be at the root of the archive.  

You are now ready to package and upload your mod.

## Distribute Your Mod
**Go to** [https://mod.io/g/rooftops-alleys](https://mod.io/g/rooftops-alleys).  
Create an account or log in to an existing one. Then select “Add UGC” at the top of the page. Follow the instructions and be sure to tag your mod accordingly.

### For Windows
For Windows, you will need to package the mod yourself.

First, go to your project settings inside the Unreal Editor, and follow the following settings:
1. Navigate to **_Game - Asset Manager,_** then under “Primary Asset Types to Scan” add **“/RNAModkit”** to the Directories list of **PrimaryAssetLabel**
2. Navigate to **_Project - Packaging_** and ensure that both UsePakFile and UseIoStore are set to true
3. Save

Now you are ready to package your mod with Modio UGC:
- At the top of the editor window, click on the [Mod.io](http://mod.io) widget  
![](Images/OpeningModioWidget.png)
- Now Select “Package Mods”  
![](Images/ModioWidgetPackageMod.png)
- Select your mod plugin, the Windows platform, and an output path, then click “package”. 
> **/!\\ If you forgot to download the BaseGameRelease and add it to your game folder, the packaging will fail. /!\\**
- Now, using your computer file explorer, navigate to the output folder you gave to the Modio widget.
- Select the **“Content” and “.uplugin”** file and compress them into a .**ZIP** archive

Go back on the [Mod.io](http://mod.io) web interface, and when asked to upload files for your mod, select **“Add a new file”.** Upload your ZIP archive, and under Target platforms select Standard and Windows.  
Don’t forget to **set the version number** of your mod; otherwise, it won’t get published!

If you make any changes to your mod in the future, you can re-cook it and re-package the resulting files. Then, on the [Mod.io](http://mod.io) web interface, go to **My Content → Mods** and click **“Manage”** on the mod you want to update.\
There, select **“Add a new file”**, upload your ZIP archive, and select only the Windows platform.  
Don’t forget to **update** the version number of your mod.

### For Consoles
For consoles, we will package your mod for you.

First, make sure to package your mod **source files** into a **ZIP** archive: go to your mod folder, then select the “**Content”** folder and the “.**uplugin”** file, and compress them into a ZIP archive.

Go to the Modio web interface and create a new mod. When asked to upload files for your mod, select **“With Cloud Cooking”**, upload your ZIP archive, and select all 3 platforms (PS5, XSX, and Switch 2). Your mod will be packaged and distributed for those platforms.  
Don’t forget to **set the version number** of your mod; otherwise, it won’t get published!

If you make any changes to your mod in the future, you can re-package your source files in a ZIP archive. Then, on the [Mod.io](http://mod.io) web interface, go to **My Content → Mods** and click **“Manage”** on the mod you want to update.  
There, select **“Add a new file”**, upload your ZIP archive, select **“With Cloud Cooking”,** and check the 3 platforms.  
Don’t forget to **update** the version number of your mod.

## Useful Links
Mod.io Documentation: [https://docs.mod.io/](https://docs.mod.io/)  
Mod.io UGC Documentation: [https://docs.mod.io/unreal/modio-ugc/getting-started](https://docs.mod.io/unreal/modio-ugc/getting-started)
