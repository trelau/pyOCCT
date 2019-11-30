/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Media_Timer.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Timer.hxx>
#include <Media_Frame.hxx>
#include <Image_Format.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Image_PixMap.hxx>
#include <Media_IFrameQueue.hxx>
#include <Media_BufferPool.hxx>
#include <Media_Packet.hxx>
#include <Media_CodecContext.hxx>
#include <Media_FormatContext.hxx>
#include <TCollection_AsciiString.hxx>
#include <Media_PlayerContext.hxx>
#include <OSD_Thread.hxx>
#include <Standard_Mutex.hxx>
#include <Standard_Condition.hxx>
#include <Media_Scaler.hxx>

PYBIND11_MODULE(Media, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.OSD");
py::module::import("OCCT.Image");
py::module::import("OCCT.TCollection");

struct ImportGraphic3d{
	ImportGraphic3d() { py::module::import("OCCT.Graphic3d"); }
};

// CLASS: MEDIA_TIMER
py::class_<Media_Timer, opencascade::handle<Media_Timer>, Standard_Transient> cls_Media_Timer(mod, "Media_Timer", "Auxiliary class defining the animation timer.");

// Constructors
cls_Media_Timer.def(py::init<>());

// Methods
cls_Media_Timer.def_static("get_type_name_", (const char * (*)()) &Media_Timer::get_type_name, "None");
cls_Media_Timer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_Timer::get_type_descriptor, "None");
cls_Media_Timer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_Timer::*)() const) &Media_Timer::DynamicType, "None");
cls_Media_Timer.def("ElapsedTime", (Standard_Real (Media_Timer::*)() const) &Media_Timer::ElapsedTime, "Return elapsed time in seconds.");
cls_Media_Timer.def("PlaybackSpeed", (Standard_Real (Media_Timer::*)() const) &Media_Timer::PlaybackSpeed, "Return playback speed coefficient (1.0 means normal speed).");
cls_Media_Timer.def("SetPlaybackSpeed", (void (Media_Timer::*)(const Standard_Real)) &Media_Timer::SetPlaybackSpeed, "Setup playback speed coefficient.", py::arg("theSpeed"));
cls_Media_Timer.def("IsStarted", (Standard_Boolean (Media_Timer::*)() const) &Media_Timer::IsStarted, "Return true if timer has been started.");
cls_Media_Timer.def("Start", (void (Media_Timer::*)()) &Media_Timer::Start, "Start the timer.");
cls_Media_Timer.def("Pause", (void (Media_Timer::*)()) &Media_Timer::Pause, "Pause the timer.");
cls_Media_Timer.def("Stop", (void (Media_Timer::*)()) &Media_Timer::Stop, "Stop the timer.");
cls_Media_Timer.def("Seek", (void (Media_Timer::*)(const Standard_Real)) &Media_Timer::Seek, "Seek the timer to specified position.", py::arg("theTime"));

// CLASS: MEDIA_FRAME
py::class_<Media_Frame, opencascade::handle<Media_Frame>, Standard_Transient> cls_Media_Frame(mod, "Media_Frame", "AVFrame wrapper - the frame (decoded image/audio sample data) holder.");

// Constructors
cls_Media_Frame.def(py::init<>());

// Methods
cls_Media_Frame.def_static("get_type_name_", (const char * (*)()) &Media_Frame::get_type_name, "None");
cls_Media_Frame.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_Frame::get_type_descriptor, "None");
cls_Media_Frame.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_Frame::*)() const) &Media_Frame::DynamicType, "None");
cls_Media_Frame.def_static("FormatFFmpeg2Occt_", (Image_Format (*)(int)) &Media_Frame::FormatFFmpeg2Occt, "Convert pixel format from FFmpeg (AVPixelFormat) to OCCT.", py::arg("theFormat"));
cls_Media_Frame.def_static("FormatOcct2FFmpeg_", (int (*)(Image_Format)) &Media_Frame::FormatOcct2FFmpeg, "Convert pixel format from OCCT to FFmpeg (AVPixelFormat). Returns -1 (AV_PIX_FMT_NONE) if undefined.", py::arg("theFormat"));
cls_Media_Frame.def_static("Swap_", (void (*)(const opencascade::handle<Media_Frame> &, const opencascade::handle<Media_Frame> &)) &Media_Frame::Swap, "Swap AVFrame* within two frames.", py::arg("theFrame1"), py::arg("theFrame2"));
cls_Media_Frame.def("IsEmpty", (bool (Media_Frame::*)() const) &Media_Frame::IsEmpty, "Return true if frame does not contain any data.");
cls_Media_Frame.def("Unref", (void (Media_Frame::*)()) &Media_Frame::Unref, "av_frame_unref() wrapper.");
cls_Media_Frame.def("Size", (Graphic3d_Vec2i (Media_Frame::*)() const) &Media_Frame::Size, "Return image dimensions.", py::call_guard<ImportGraphic3d>());
cls_Media_Frame.def("SizeX", (int (Media_Frame::*)() const) &Media_Frame::SizeX, "Return image width.");
cls_Media_Frame.def("SizeY", (int (Media_Frame::*)() const) &Media_Frame::SizeY, "Return image height.");
cls_Media_Frame.def("Format", (int (Media_Frame::*)() const) &Media_Frame::Format, "Return pixel format (AVPixelFormat).");
cls_Media_Frame.def("IsFullRangeYUV", (bool (Media_Frame::*)() const) &Media_Frame::IsFullRangeYUV, "Return TRUE if YUV range is full.");
cls_Media_Frame.def("Plane", (uint8_t * (Media_Frame::*)(int) const) &Media_Frame::Plane, "Access data plane for specified Id.", py::arg("thePlaneId"));
cls_Media_Frame.def("LineSize", (int (Media_Frame::*)(int) const) &Media_Frame::LineSize, "Returns linesize in bytes for specified data plane", py::arg("thePlaneId"));
cls_Media_Frame.def("BestEffortTimestamp", (int64_t (Media_Frame::*)() const) &Media_Frame::BestEffortTimestamp, "Returns frame timestamp estimated using various heuristics, in stream time base");
// cls_Media_Frame.def("Frame", (const AVFrame * (Media_Frame::*)() const) &Media_Frame::Frame, "Return frame.");
// cls_Media_Frame.def("ChangeFrame", (AVFrame * (Media_Frame::*)()) &Media_Frame::ChangeFrame, "Return frame.");
cls_Media_Frame.def("Pts", (double (Media_Frame::*)() const) &Media_Frame::Pts, "Return presentation timestamp (PTS).");
cls_Media_Frame.def("SetPts", (void (Media_Frame::*)(double)) &Media_Frame::SetPts, "Set presentation timestamp (PTS).", py::arg("thePts"));
cls_Media_Frame.def("PixelAspectRatio", (float (Media_Frame::*)() const) &Media_Frame::PixelAspectRatio, "Return PAR.");
cls_Media_Frame.def("SetPixelAspectRatio", (void (Media_Frame::*)(float)) &Media_Frame::SetPixelAspectRatio, "Set PAR.", py::arg("theRatio"));
cls_Media_Frame.def("IsLocked", (bool (Media_Frame::*)() const) &Media_Frame::IsLocked, "Return locked state.");
cls_Media_Frame.def("SetLocked", (void (Media_Frame::*)(bool)) &Media_Frame::SetLocked, "Lock/free frame for edition.", py::arg("theToLock"));
cls_Media_Frame.def("InitWrapper", (bool (Media_Frame::*)(const opencascade::handle<Image_PixMap> &)) &Media_Frame::InitWrapper, "Wrap allocated image pixmap.", py::arg("thePixMap"));

// CLASS: MEDIA_IFRAMEQUEUE
py::class_<Media_IFrameQueue> cls_Media_IFrameQueue(mod, "Media_IFrameQueue", "Interface defining frame queuing.");

// Methods
cls_Media_IFrameQueue.def("LockFrame", (opencascade::handle<Media_Frame> (Media_IFrameQueue::*)()) &Media_IFrameQueue::LockFrame, "Lock the frame, e.g. take ownership on a single (not currently displayed) frame from the queue to perform decoding into.");
cls_Media_IFrameQueue.def("ReleaseFrame", (void (Media_IFrameQueue::*)(const opencascade::handle<Media_Frame> &)) &Media_IFrameQueue::ReleaseFrame, "Release previously locked frame, e.g. it can be displayed on the screen.", py::arg("theFrame"));

// CLASS: MEDIA_BUFFERPOOL
py::class_<Media_BufferPool, opencascade::handle<Media_BufferPool>, Standard_Transient> cls_Media_BufferPool(mod, "Media_BufferPool", "AVBufferPool wrapper.");

// Constructors
cls_Media_BufferPool.def(py::init<>());

// Methods
cls_Media_BufferPool.def_static("get_type_name_", (const char * (*)()) &Media_BufferPool::get_type_name, "None");
cls_Media_BufferPool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_BufferPool::get_type_descriptor, "None");
cls_Media_BufferPool.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_BufferPool::*)() const) &Media_BufferPool::DynamicType, "None");
cls_Media_BufferPool.def("Release", (void (Media_BufferPool::*)()) &Media_BufferPool::Release, "Release the pool (reference-counted buffer will be released when needed).");
cls_Media_BufferPool.def("Init", (bool (Media_BufferPool::*)(int)) &Media_BufferPool::Init, "(Re-)initialize the pool.", py::arg("theBufferSize"));
cls_Media_BufferPool.def("BufferSize", (int (Media_BufferPool::*)() const) &Media_BufferPool::BufferSize, "Return buffer size within the pool.");
// cls_Media_BufferPool.def("GetBuffer", (AVBufferRef * (Media_BufferPool::*)()) &Media_BufferPool::GetBuffer, "Get new buffer from the pool.");

// CLASS: MEDIA_PACKET
py::class_<Media_Packet, opencascade::handle<Media_Packet>, Standard_Transient> cls_Media_Packet(mod, "Media_Packet", "AVPacket wrapper - the packet (data chunk for decoding/encoding) holder.");

// Constructors
cls_Media_Packet.def(py::init<>());

// Methods
cls_Media_Packet.def_static("get_type_name_", (const char * (*)()) &Media_Packet::get_type_name, "None");
cls_Media_Packet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_Packet::get_type_descriptor, "None");
cls_Media_Packet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_Packet::*)() const) &Media_Packet::DynamicType, "None");
cls_Media_Packet.def("Unref", (void (Media_Packet::*)()) &Media_Packet::Unref, "av_packet_unref() wrapper.");
// cls_Media_Packet.def("Packet", (const AVPacket * (Media_Packet::*)() const) &Media_Packet::Packet, "Return packet.");
// cls_Media_Packet.def("ChangePacket", (AVPacket * (Media_Packet::*)()) &Media_Packet::ChangePacket, "Return packet.");
cls_Media_Packet.def("Data", (const uint8_t * (Media_Packet::*)() const) &Media_Packet::Data, "Return data.");
cls_Media_Packet.def("ChangeData", (uint8_t * (Media_Packet::*)()) &Media_Packet::ChangeData, "Return data.");
cls_Media_Packet.def("Size", (int (Media_Packet::*)() const) &Media_Packet::Size, "Return data size.");
cls_Media_Packet.def("Pts", (int64_t (Media_Packet::*)() const) &Media_Packet::Pts, "Return presentation timestamp (PTS).");
cls_Media_Packet.def("Dts", (int64_t (Media_Packet::*)() const) &Media_Packet::Dts, "Return decoding timestamp (DTS).");
cls_Media_Packet.def("Duration", (int64_t (Media_Packet::*)() const) &Media_Packet::Duration, "Return Duration.");
cls_Media_Packet.def("DurationSeconds", (double (Media_Packet::*)() const) &Media_Packet::DurationSeconds, "Return Duration in seconds.");
cls_Media_Packet.def("SetDurationSeconds", (void (Media_Packet::*)(double)) &Media_Packet::SetDurationSeconds, "Set Duration in seconds.", py::arg("theDurationSec"));
cls_Media_Packet.def("StreamIndex", (int (Media_Packet::*)() const) &Media_Packet::StreamIndex, "Return stream index.");
cls_Media_Packet.def("IsKeyFrame", (bool (Media_Packet::*)() const) &Media_Packet::IsKeyFrame, "Return TRUE for a key frame.");
cls_Media_Packet.def("SetKeyFrame", (void (Media_Packet::*)()) &Media_Packet::SetKeyFrame, "Mark as key frame.");

// CLASS: MEDIA_CODECCONTEXT
py::class_<Media_CodecContext, opencascade::handle<Media_CodecContext>, Standard_Transient> cls_Media_CodecContext(mod, "Media_CodecContext", "AVCodecContext wrapper - the coder/decoder holder.");

// Constructors
cls_Media_CodecContext.def(py::init<>());

// Methods
cls_Media_CodecContext.def_static("get_type_name_", (const char * (*)()) &Media_CodecContext::get_type_name, "None");
cls_Media_CodecContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_CodecContext::get_type_descriptor, "None");
cls_Media_CodecContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_CodecContext::*)() const) &Media_CodecContext::DynamicType, "None");
// cls_Media_CodecContext.def("Context", (AVCodecContext * (Media_CodecContext::*)() const) &Media_CodecContext::Context, "Return context.");
// cls_Media_CodecContext.def("Init", [](Media_CodecContext &self, const AVStream & a0, double a1) -> bool { return self.Init(a0, a1); });
// cls_Media_CodecContext.def("Init", (bool (Media_CodecContext::*)(const AVStream &, double, int)) &Media_CodecContext::Init, "Open codec specified within the stream.", py::arg("theStream"), py::arg("thePtsStartBase"), py::arg("theNbThreads"));
// cls_Media_CodecContext.def("Init", (bool (Media_CodecContext::*)(const AVStream &, double, int, int)) &Media_CodecContext::Init, "Open codec.", py::arg("theStream"), py::arg("thePtsStartBase"), py::arg("theNbThreads"), py::arg("theCodecId"));
cls_Media_CodecContext.def("Close", (void (Media_CodecContext::*)()) &Media_CodecContext::Close, "Close input.");
cls_Media_CodecContext.def("SizeX", (int (Media_CodecContext::*)() const) &Media_CodecContext::SizeX, "Returns source frame width");
cls_Media_CodecContext.def("SizeY", (int (Media_CodecContext::*)() const) &Media_CodecContext::SizeY, "Returns source frame height");
cls_Media_CodecContext.def("StreamIndex", (int (Media_CodecContext::*)() const) &Media_CodecContext::StreamIndex, "Return stream index.");
cls_Media_CodecContext.def("Flush", (void (Media_CodecContext::*)()) &Media_CodecContext::Flush, "avcodec_flush_buffers() wrapper.");
cls_Media_CodecContext.def("CanProcessPacket", (bool (Media_CodecContext::*)(const opencascade::handle<Media_Packet> &) const) &Media_CodecContext::CanProcessPacket, "Return true if packet belongs to this stream.", py::arg("thePacket"));
cls_Media_CodecContext.def("SendPacket", (bool (Media_CodecContext::*)(const opencascade::handle<Media_Packet> &)) &Media_CodecContext::SendPacket, "avcodec_send_packet() wrapper.", py::arg("thePacket"));
cls_Media_CodecContext.def("ReceiveFrame", (bool (Media_CodecContext::*)(const opencascade::handle<Media_Frame> &)) &Media_CodecContext::ReceiveFrame, "avcodec_receive_frame() wrapper.", py::arg("theFrame"));

// CLASS: MEDIA_FORMATCONTEXT
py::class_<Media_FormatContext, opencascade::handle<Media_FormatContext>, Standard_Transient> cls_Media_FormatContext(mod, "Media_FormatContext", "AVFormatContext wrapper - the media input/output stream holder.");

// Constructors
cls_Media_FormatContext.def(py::init<>());

// Methods
cls_Media_FormatContext.def_static("get_type_name_", (const char * (*)()) &Media_FormatContext::get_type_name, "None");
cls_Media_FormatContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_FormatContext::get_type_descriptor, "None");
cls_Media_FormatContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_FormatContext::*)() const) &Media_FormatContext::DynamicType, "None");
cls_Media_FormatContext.def_static("FormatAVErrorDescription_", (TCollection_AsciiString (*)(int)) &Media_FormatContext::FormatAVErrorDescription, "Returns string description for AVError code.", py::arg("theErrCodeAV"));
cls_Media_FormatContext.def_static("FormatUnitsToSeconds_", (double (*)(int64_t)) &Media_FormatContext::FormatUnitsToSeconds, "Convert time units into seconds for context.", py::arg("theTimeUnits"));
// cls_Media_FormatContext.def_static("UnitsToSeconds_", (double (*)(const AVRational &, int64_t)) &Media_FormatContext::UnitsToSeconds, "Convert time units into seconds. Returns zero for invalid value.", py::arg("theTimeBase"), py::arg("theTimeUnits"));
// cls_Media_FormatContext.def_static("StreamUnitsToSeconds_", (double (*)(const AVStream &, int64_t)) &Media_FormatContext::StreamUnitsToSeconds, "Convert time units into seconds using stream base.", py::arg("theStream"), py::arg("theTimeUnits"));
// cls_Media_FormatContext.def_static("SecondsToUnits_", (int64_t (*)(double)) &Media_FormatContext::SecondsToUnits, "Convert seconds into time units for context.", py::arg("theTimeSeconds"));
// cls_Media_FormatContext.def_static("SecondsToUnits_", (int64_t (*)(const AVRational &, double)) &Media_FormatContext::SecondsToUnits, "Convert seconds into time units.", py::arg("theTimeBase"), py::arg("theTimeSeconds"));
// cls_Media_FormatContext.def_static("StreamSecondsToUnits_", (int64_t (*)(const AVStream &, double)) &Media_FormatContext::StreamSecondsToUnits, "Convert seconds into time units for stream.", py::arg("theStream"), py::arg("theTimeSeconds"));
cls_Media_FormatContext.def_static("FormatTime_", (TCollection_AsciiString (*)(double)) &Media_FormatContext::FormatTime, "Time formatter.", py::arg("theSeconds"));
cls_Media_FormatContext.def_static("FormatTimeProgress_", (TCollection_AsciiString (*)(double, double)) &Media_FormatContext::FormatTimeProgress, "Time progress / duration formatter.", py::arg("theProgress"), py::arg("theDuration"));
// cls_Media_FormatContext.def("Context", (AVFormatContext * (Media_FormatContext::*)() const) &Media_FormatContext::Context, "Return context.");
cls_Media_FormatContext.def("OpenInput", (bool (Media_FormatContext::*)(const TCollection_AsciiString &)) &Media_FormatContext::OpenInput, "Open input.", py::arg("theInput"));
cls_Media_FormatContext.def("Close", (void (Media_FormatContext::*)()) &Media_FormatContext::Close, "Close input.");
cls_Media_FormatContext.def("NbSteams", (unsigned int (Media_FormatContext::*)() const) &Media_FormatContext::NbSteams, "Return amount of streams.");
// cls_Media_FormatContext.def("Stream", (const AVStream & (Media_FormatContext::*)(unsigned int) const) &Media_FormatContext::Stream, "Return stream.", py::arg("theIndex"));
// cls_Media_FormatContext.def("StreamInfo", [](Media_FormatContext &self, unsigned int a0) -> TCollection_AsciiString { return self.StreamInfo(a0); });
// cls_Media_FormatContext.def("StreamInfo", (TCollection_AsciiString (Media_FormatContext::*)(unsigned int, AVCodecContext *) const) &Media_FormatContext::StreamInfo, "Format stream info.", py::arg("theIndex"), py::arg("theCodecCtx"));
cls_Media_FormatContext.def("PtsStartBase", (double (Media_FormatContext::*)() const) &Media_FormatContext::PtsStartBase, "Return PTS start base in seconds.");
cls_Media_FormatContext.def("Duration", (double (Media_FormatContext::*)() const) &Media_FormatContext::Duration, "Return duration in seconds.");
cls_Media_FormatContext.def("ReadPacket", (bool (Media_FormatContext::*)(const opencascade::handle<Media_Packet> &)) &Media_FormatContext::ReadPacket, "av_read_frame() wrapper.", py::arg("thePacket"));
cls_Media_FormatContext.def("SeekStream", (bool (Media_FormatContext::*)(unsigned int, double, bool)) &Media_FormatContext::SeekStream, "Seek stream to specified position.", py::arg("theStreamId"), py::arg("theSeekPts"), py::arg("toSeekBack"));
cls_Media_FormatContext.def("Seek", (bool (Media_FormatContext::*)(double, bool)) &Media_FormatContext::Seek, "Seek context to specified position.", py::arg("theSeekPts"), py::arg("toSeekBack"));

// CLASS: MEDIA_PLAYERCONTEXT
py::class_<Media_PlayerContext, opencascade::handle<Media_PlayerContext>, Standard_Transient> cls_Media_PlayerContext(mod, "Media_PlayerContext", "Player context.");

// Constructors
cls_Media_PlayerContext.def(py::init<Media_IFrameQueue *>(), py::arg("theFrameQueue"));

// Methods
cls_Media_PlayerContext.def_static("get_type_name_", (const char * (*)()) &Media_PlayerContext::get_type_name, "None");
cls_Media_PlayerContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_PlayerContext::get_type_descriptor, "None");
cls_Media_PlayerContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_PlayerContext::*)() const) &Media_PlayerContext::DynamicType, "None");
cls_Media_PlayerContext.def_static("DumpFirstFrame_", (opencascade::handle<Media_Frame> (*)(const TCollection_AsciiString &, TCollection_AsciiString &)) &Media_PlayerContext::DumpFirstFrame, "Dump first video frame.", py::arg("theSrcVideo"), py::arg("theMediaInfo"));
cls_Media_PlayerContext.def_static("DumpFirstFrame_", [](const TCollection_AsciiString & a0, const TCollection_AsciiString & a1, TCollection_AsciiString & a2) -> bool { return Media_PlayerContext::DumpFirstFrame(a0, a1, a2); });
cls_Media_PlayerContext.def_static("DumpFirstFrame_", (bool (*)(const TCollection_AsciiString &, const TCollection_AsciiString &, TCollection_AsciiString &, int)) &Media_PlayerContext::DumpFirstFrame, "Dump first video frame.", py::arg("theSrcVideo"), py::arg("theOutImage"), py::arg("theMediaInfo"), py::arg("theMaxSize"));
cls_Media_PlayerContext.def("SetInput", (void (Media_PlayerContext::*)(const TCollection_AsciiString &, Standard_Boolean)) &Media_PlayerContext::SetInput, "Set new input for playback.", py::arg("theInputPath"), py::arg("theToWait"));
cls_Media_PlayerContext.def("PlaybackState", [](Media_PlayerContext &self, Standard_Boolean & theIsPaused, Standard_Real & theProgress, Standard_Real & theDuration){ self.PlaybackState(theIsPaused, theProgress, theDuration); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(theIsPaused, theProgress, theDuration); }, "Return playback state.", py::arg("theIsPaused"), py::arg("theProgress"), py::arg("theDuration"));
cls_Media_PlayerContext.def("PlayPause", [](Media_PlayerContext &self, Standard_Boolean & theIsPaused, Standard_Real & theProgress, Standard_Real & theDuration){ self.PlayPause(theIsPaused, theProgress, theDuration); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(theIsPaused, theProgress, theDuration); }, "Pause/Pause playback depending on the current state.", py::arg("theIsPaused"), py::arg("theProgress"), py::arg("theDuration"));
cls_Media_PlayerContext.def("Seek", (void (Media_PlayerContext::*)(Standard_Real)) &Media_PlayerContext::Seek, "Seek to specified position.", py::arg("thePosSec"));
cls_Media_PlayerContext.def("Pause", (void (Media_PlayerContext::*)()) &Media_PlayerContext::Pause, "Pause playback.");
cls_Media_PlayerContext.def("Resume", (void (Media_PlayerContext::*)()) &Media_PlayerContext::Resume, "Resume playback.");
cls_Media_PlayerContext.def("ToForceRgb", (bool (Media_PlayerContext::*)() const) &Media_PlayerContext::ToForceRgb, "Return TRUE if queue requires RGB pixel format or can handle also YUV pixel format; TRUE by default.");
cls_Media_PlayerContext.def("SetForceRgb", (void (Media_PlayerContext::*)(bool)) &Media_PlayerContext::SetForceRgb, "Set if queue requires RGB pixel format or can handle also YUV pixel format.", py::arg("theToForce"));

// CLASS: MEDIA_SCALER
py::class_<Media_Scaler, opencascade::handle<Media_Scaler>, Standard_Transient> cls_Media_Scaler(mod, "Media_Scaler", "SwsContext wrapper - tool performing image scaling and pixel format conversion.");

// Constructors
cls_Media_Scaler.def(py::init<>());

// Methods
cls_Media_Scaler.def_static("get_type_name_", (const char * (*)()) &Media_Scaler::get_type_name, "None");
cls_Media_Scaler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_Scaler::get_type_descriptor, "None");
cls_Media_Scaler.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_Scaler::*)() const) &Media_Scaler::DynamicType, "None");
cls_Media_Scaler.def("Release", (void (Media_Scaler::*)()) &Media_Scaler::Release, "sws_freeContext() wrapper.");
cls_Media_Scaler.def("Init", (bool (Media_Scaler::*)(const Graphic3d_Vec2i &, int, const Graphic3d_Vec2i &, int)) &Media_Scaler::Init, "sws_getContext() wrapper - creates conversion context.", py::arg("theSrcDims"), py::arg("theSrcFormat"), py::arg("theResDims"), py::arg("theResFormat"), py::call_guard<ImportGraphic3d>());
cls_Media_Scaler.def("Convert", (bool (Media_Scaler::*)(const opencascade::handle<Media_Frame> &, const opencascade::handle<Media_Frame> &)) &Media_Scaler::Convert, "Convert one frame to another.", py::arg("theSrc"), py::arg("theRes"));
cls_Media_Scaler.def("IsValid", (bool (Media_Scaler::*)() const) &Media_Scaler::IsValid, "Return TRUE if context was initialized.");


}
