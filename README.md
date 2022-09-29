# Ready Player Me UE5 Third Person Character Example

![img-readyplayerme-character](https://user-images.githubusercontent.com/7085672/163189054-ceeda1d9-1982-4b39-9517-1bd758c746b3.png)

This repository contains an example Unreal Engine 5 project that creates a character controller using a Ready Player Me avatar. This is to serve as a reference for anybody that wants to integrate our 3D avatars into their Unreal Engine project. 

# Map

The ThirdPersonExampleMap is loaded on startup by default and can be found in the projects `Content > ReadyPlayerMe > Maps` folder as below.

![img-maps](https://user-images.githubusercontent.com/7085672/163190404-9bd95c07-9cf1-4dee-b6c3-1a5829be5d2c.png)

There is no custom code or actors in this map however if you open up the World Settings you will notice we set a GameMode Override to use our TP_GameMode asset. This game mode is used to set the Default Pawn Class to be our RPM_ThirdPersonCharacter.

![img-game-mode](https://user-images.githubusercontent.com/7085672/163191426-5f871707-eeba-4318-918f-12648419ea79.png)

# Character Blueprint

You can find our character blueprint named `RPM_ThirdPersonCharacter` in the projects `Content > ReadyPlayerMe > Blueprints` folder. 

This character was created simply by duplicating the example Unreal Third Person Character blueprint (that uses mannequin skeleton and mesh), then we reassigned the skeletal mesh and the animation blueprint as well as added a ReadyPlayerMeComponent to handle the loading of our ReadyPlayerMe avatars at runtime. 

# Animations 

If you look in the folder `Content > ReadyPlayerMe > Animations` you will find all the animations, blendspaces and animation blueprints used in our example.

![img-animations](https://user-images.githubusercontent.com/7085672/163196240-fa3186db-6fca-4ca4-8639-d0c5754490d7.png)

# Avatar Loader UI Widget

The Avatar Loader UI Widget get be found in `Content > ReadyPlayerMe > Widgets`.

![img-ui-widget](https://user-images.githubusercontent.com/7085672/163198531-ea688571-c43c-4931-8254-3fc49734865e.png)

When you run the application and press Q the UI panel should display as below.

![img-avatar-loader-ui](https://user-images.githubusercontent.com/7085672/163198553-23941483-28b8-4450-b206-faee776931d3.png)

# How to retarget animations

While our avatars use a skeleton rig based on the Mixamo skeleton, it is possible to retarget animations using the UE4 and UE5 Mannequin skeletons so that they work with our Ready Player Me Avatars. For this example we did exactly that, to retarget animations from the UE5 Mannequn skeleton we first had to setup the IK Rig for the RPM skeleton. Right click in the asset browser and from the `Animation > IK Rig`, now we need to pick the `RPM_Mixamo_SkeletalMesh` skeletal mesh. To do this you need to open up the `UE4_Mannequin_Skeleton` asset located at `Content > Mannequin > Character > Mesh`. 

Different skeletons have different amount of bones, we need to create **IK Chains** so that the chains will match the chains in IK Rig of the UE5 Mannequin. We need to also add **IK Solver** for better retargeting. The same IK Rig can be used to retarget animations between Meshes that have different skeletons. You can find more details about UE5 retargeting in the official UE5 Documentation.

Now we need to create an IK Retargeter that will retarget the animations from UE5 Mannequin to RPM. In the Content Browser right click `Animation > IK Retargeter` Pick the **IK_Mannequin**. UE5 example project comes with IK Rigs for UE4 and UE5 Mannequins. In the newly created retargeter set the **TargetIKRigAsset** to our RPM IK Rig. The two meshes will appear side-by-side. We need to make sure that all the chains are assigned correctly between the two skeletons. Now we need to create a new pose and adjust the pose of the RPM avatar to be ask close to the pose of the Mannequin as possible.

We can do the same steps to create UE4_Mannequin to RPM retargeter, if we need to retarget the animations from the UE4 Mannequin.

We are almost there. Now we can retarget the animations. If you retarget an **Animation Blueprint** it will retarget and create a copy of every animation and blendspaces that is used in the blueprint as well as create a new Animation Blueprint. Right click on the **ABP_Manny** `Retarget Animation Assets > Duplicate and Retarget Animation Blueprint`, This will open the retargeting window. We can add a prefix or suffix for the retargeted animations. Select the newly created IK Retargeter, set the folder the retargeted animations animations, click **Retarge**. This will create an animation blueprint along with all of the retargeted animations.


![img-retargeting-panel](https://user-images.githubusercontent.com/7085672/163196328-170b7e9d-fc30-47c5-8487-0e4d7c3fbbf2.png)

In our case we will use the `ThirdPerson_AnimBP` located at `Content > Mannequin > Animations` as an example. Simply right click and select `Retarget Anim Blueprints > Duplicate Anim Blueprints and Retarget`. 

![img-retarget-menu](https://user-images.githubusercontent.com/7085672/163198242-a774dbdd-b41b-46f7-ab2c-3d1d0af09441.png)

This will bring up the Select Skeleton window, in here simply select the `RPM_Mixamo_Skeleton` asset and click retarget. 

![img-select-skeleton](https://user-images.githubusercontent.com/7085672/163198391-ef5989e7-cda0-4cc5-8281-a6a515581a15.png)

Once the process is complete we should end up with animations and/or animation blueprints that work with our Ready Player Me avatar.

When we run the game we will notice that the feet of the character are stuck to the ground.This is because the default **Control Rig** uses bones specific to the Mannequin skeleton. We need to disable the IK from our animation blueprint. Open the animation blueprint and remove the control rig from the execution chain. There will be IK support in the upcoming versions of the SDK.

Make sure to assign the Override Physical Asset in the SkeletalMeshComponent of the character blueprint. You might encounter issues with shadows otherwise.

## Dependencies
- Ready Player Me Unreal SDK 
- glTFRuntime (Third party plugin)

## Links
**Ready Player Me Unreal SDK**
- [Documentation](https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-engine-4)
- [Download](https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-engine-4/unreal-plugin-download)
- [Support](https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-engine-4/troubleshooting)

**glTFRuntime**
- [Documentation](https://github.com/rdeioris/glTFRuntime-docs/blob/master/README.md)



