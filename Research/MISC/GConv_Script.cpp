// ============================================================================
// GCONV 3.5 API - C++ ENGINE METHOD DECLARATIONS
// Extracted from gconvapi.dll & script compilers (*.qsc, *.qvm, *.dat, *.mtp)
// ============================================================================

// --- CORE DLL ENGINE EXPORTS ---
void gcInit();
void gcFree(void* ptr);
void* gcMalloc(int size);
int gcParseCommandLine(string cmdLine);
void gcExecuteScript(string scriptPath);
void gcSetErrorCallback(void* callbackFunc);
void gcSetFreeCallback(void* callbackFunc);
void gcSetMallocCallback(void* callbackFunc);
void gcSetMessageCallback(void* callbackFunc);
void gcNewOption(string optionName, string value);
void gcOverrideUpToDateCheck(bool bOverride);
string gcGetInputPath();
string gcGetOutputPath();
string gcGetTempPath();
int gcGetNumberOfErrors();
void gcMessage(string messageText);
void gcError(string errorText);
void gcSetInputPath(string path);
void gcSetOutputPath(string path);
void gcSetTempPath(string path);
void gcSetOutputMode(string platformMode);       // e.g., "PC_Glide", "Dreamcast", "N64"
void gcSetTextureFormat(string format);          // e.g., "ARGB1555", "ARGB8888", "RGB565"
void gcSetErrorLevel(int level);                 // 0: Ignore, 1: stderr, 2: Dialog, 3: Abort
void gcSetVerbosity(int level);                  // Message detail logging level (0 to 5)
void gcSetAutoMipmap(bool bEnable);
void gcSetAutoVQ(bool bEnable);
void gcSetDithering(bool bEnable);
void gcSetTransparency(bool bEnable);
void gcSetTransparentColour(int colorIndex);

// --- VIRTUAL FILE SYSTEM (VFS) RESOURCE BUNDLING ---
void BeginResource(string resourcePath);
void AddResource(string virtualName, string localPath);
void AddStringResource(string textKey, string textValue);
void AddDirectoryResource(string folderRoute);
void EndResource();
void DumpResource(string resourcePath);
void ExtractResource(string targetElement);
void ReplaceApostrophes(bool bEnable);
void StripResourceDebug(bool bEnable);
void IncludeResourceDebug(bool bEnable);
void DefaultAlignment(int byteAlignment);

// --- GRAPHICS & TEXTURE PROCESSING PIPELINE ---
void MakeTexture(string sourceImage, string targetTex);
void MakeMultiTexture(string configFilename);
void MakePicture(string sourceImage, string targetPic);
void MakeSprite(string sourceImage, string targetSpr);
void MakeTGA(string sourceFile, string destTga);
void MakeTGARecursive(string folderRoute);        // Performs batch updates on structural graphics trees to Targa formats
void MakePalette(string sourceImage, string targetPal);
void ReduceColours(string sourceImage, int colorCount);
void BeginPalette(string palettePath);
void AddPaletteImage(string sourceImage);
void EndPalette();
void LoadPalette(string palettePath);
void RemapImage(string sourceImage);
void FlipTileCheck(bool bEnable);
void EqualTileCheck(bool bEnable);
void SemiTransparency(bool bEnable);

// --- TYPOGRAPHY & FONT MANAGEMENT ---
void NewFont(string fontIdName);
void MakeFont(string fontSheetImage, string targetFont);
void DumpFont(string fontFile);
void MakeOutline(int pixelThickness);
void SetTileSize(int width, int height);
void SetCharSpacing(int defaultPixels);
void AdjustCharPosition(int charCode, int xOffset, int yOffset);
void AdjustCharSpacing(int charCode, int extraPixels);
void SetCharParts(int charCode, int totalElements);
void SetFontTable(string layoutMappingString);
void FontAutoScan(bool bEnable);
void FontType(string typeMode);                   // "FIXEDSIZE" or "PROPORTIONAL"

// --- 3D MESH COMPILATION & MATERIAL BINDING ---
void CreateVirtualModel(string modelName, string baseAsset);
void CreateModelRigidNotVirtual(string meshName);
void CreateModelBoneNotVirtual(string meshName);
void CreateCompleteModelRigid(string meshName);
void CreateCompleteModelBone(string meshName);
void CreateCompleteModelLightmap(string meshName);
void CreateShadowVolume(string meshName);
void NewObject(string segmentName);
void AttachObject(string itemLabel);
void AttachObjectBoneID(string itemLabel, int boneIndex);
void Vertex(float x, float y, float z);
void Normal(float nx, float ny, float nz);
void UV(float u, float v);
void Face(int v1, int v2, int v3);
void MagicVertex(int typeFlag, int indexValue);
void VertexInfluenceRigid(int jointId, float weightValue);
void VertexInfluenceType(string trackingMethodName);
void MorphChannel(int channelIndex);
void MorphVertex(int vertexIndex, float x, float y, float z);
void Glow(string glowTypeFlag);
void Material(string profileLabel);
void MaterialTransparencyType(int blendModeId);
void MaterialShininess(float intensityValue);
void DiffuseTMap(string textureFilename);
void AmbientTMap(string textureFilename);
void BumpTMap(string textureFilename);
void ReflectionTMap(string textureFilename);
void OpacityTMap(string textureFilename);
void Convert();
void ConvertRigidDirect3D();
void ConvertShadowDirect3D();
void ConvertBoneDirect3D();
void ConvertLightmapDirect3D();

// --- SKELETAL KEYFRAME ANIMATION SYSTEM ---
void NewAnim(string animationId);
void BeginAnim(string animationId);
void BeginSwappedAnim(string animationId);
void AddAnimFrame(string sourceFrameFile);
void MakeAnim(string animationId);
void EndAnim();
void SetScale(float scalingFactor);
void AnimAttachObject(string subMeshLabel);
void AnimAttachObjectBoneID(string subMeshLabel, int jointId);
void AttachObjectKeyFrame(int frameTimeIndex);
void AttachObjectKeyFrameInit();
void TranslationKeyFrameData(int timeStamp, float x, float y, float z);
void TranslationKeyFrameInit();
void RotationKeyFrameData(int timeStamp, float qx, float qy, float qz, float qw); // Quaternion rotation
void RotationKeyFrameInit();
void LinkEvent(int timeStamp, string eventStringId);
void TriggerData(int timeStamp, string scriptActionCode);
void TriggerInit();
void AnimInit();
void CreateAnim(string targetFilename);
void CreateAnimRandomAccess(string targetFilename);
void SetAnimDirectory(string path);

// --- TEXTURE SCRIPT CONTEXTS (*.dat / *.mtp) ---
void StartTexScript();
void EndTexScript();
void UseEmptyCommon();
void LoadCommon(string trackingDatabasePath);
void BuildDynamic();
void BuildStatic();
void DefinePaletteInVirTex(string paletteId);
void DefineVirTex(string virtualTextureIdName);
void SetModelDirectory(string path);
void SetTextureDirectory(string path);
void SetPaletteDirectory(string path);
void SetTempDirectory(string path);
void SetTargetPlatform(string systemName);
void SetLightmapResolution(int pixelsSquare);
void SetLightmapResolutionDivider(int divisorScale);
void CheckTextureAlpha(string imageFilename);
void AddToTextureScript(string assetLabelName);
void Parse(string scriptFilename);
void Output(string targetFilename);
void Set100TransOnlyCollPoly(bool bEnable);

// --- AUDIO & CODE PATCH SCRIPTS ---
void DefaultSoundConvertMethod(string modeMethod); // e.g., "SOUNDPACKMETHOD_ADPCM_RESIDENT"
void ConvertSoundFile(string inputWav, string outputFormat);
void ConvertSoundFileToResource(string sourceWav, string targetRes);
void ConvertSoundFileToLipsyncResource(string wav, string res, float threshold);
void CompilePatch(string scriptPath, string targetPatchFile);
void BuildPatch();
void PatchIgnoreFile(string trackingFilename);

// --- SCRIPT COMPILATION & VM CONTROLS (*.qsc / *.qvm) ---
void CompileScript(string scriptFile, string targetQvm);
void CompileScriptsRecursive(string rootFolder);
void LoadScript(string targetQvm);
void Exec();
void BreakScript();
void _Script_SetWarningLevel(string severityLevelFlag);
