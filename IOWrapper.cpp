#include "imguiWrappedHeader.h"
#include "IOWrapper.h"
#include "WrapperConverter.h"

#include <string>

IggBool iggWantCaptureMouse(IggIO handle)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   return io->WantCaptureMouse ? 1 : 0;
}

IggBool iggWantCaptureKeyboard(IggIO handle)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   return io->WantCaptureKeyboard ? 1 : 0;
}

IggBool iggWantTextInput(IggIO handle)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   return io->WantTextInput ? 1 : 0;
}

IggFontAtlas iggIoGetFonts(IggIO handle)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   return reinterpret_cast<IggFontAtlas>(io->Fonts);
}

void iggIoSetDisplaySize(IggIO handle, IggVec2 const *value)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   importValue(io->DisplaySize, *value);
}

void iggIoSetMousePosition(IggIO handle, IggVec2 const *value)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   importValue(io->MousePos, *value);
}

void iggIoSetMouseButtonDown(IggIO handle, int index, IggBool value)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   io->MouseDown[index] = value != 0;
}

void iggIoAddMouseWheelDelta(IggIO handle, float horizontal, float vertical)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   io->MouseWheelH += horizontal;
   io->MouseWheel += vertical;
}

void iggIoSetDeltaTime(IggIO handle, float value)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   io->DeltaTime = value;
}

void iggIoSetFontGlobalScale(IggIO handle, float value)
{
   ImGuiIO *io = reinterpret_cast<ImGuiIO *>(handle);
   io->FontGlobalScale = value;
}

void iggIoKeyPress(IggIO handle, int key)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeysDown[key] = true;
}

void iggIoKeyRelease(IggIO handle, int key)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeysDown[key] = false;
}

void iggIoKeyMap(IggIO handle, int imguiKey, int nativeKey)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeyMap[imguiKey] = nativeKey;
}

void iggIoKeyCtrl(IggIO handle, int leftCtrl, int rightCtrl)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeyCtrl = io.KeysDown[leftCtrl] || io.KeysDown[rightCtrl];
}

void iggIoKeyShift(IggIO handle, int leftShift, int rightShift)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeyShift = io.KeysDown[leftShift] || io.KeysDown[rightShift];
}

void iggIoKeyAlt(IggIO handle, int leftAlt, int rightAlt)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeyAlt = io.KeysDown[leftAlt] || io.KeysDown[rightAlt];
}

void iggIoKeySuper(IggIO handle, int leftSuper, int rightSuper)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.KeySuper = io.KeysDown[leftSuper] || io.KeysDown[rightSuper];
}

void iggIoAddInputCharactersUTF8(IggIO handle, char const *utf8Chars)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.AddInputCharactersUTF8(utf8Chars);
}

void iggIoSetIniFilename(IggIO handle, char const *value)
{
   static std::string bufferValue;
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   bufferValue = (value != nullptr) ? value : "";
   io.IniFilename = bufferValue.empty() ? nullptr : bufferValue.c_str();
}

void iggIoSetConfigFlags(IggIO handle, int flags)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.ConfigFlags = flags;
}

void iggIoSetBackendFlags(IggIO handle, int flags)
{
   ImGuiIO &io = *reinterpret_cast<ImGuiIO *>(handle);
   io.BackendFlags = flags;
}
