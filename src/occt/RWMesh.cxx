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
#include <RWMesh_CoordinateSystem.hxx>
#include <RWMesh_CafReader.hxx>
#include <gp_Ax3.hxx>
#include <gp.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_XYZ.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_Mat4.hxx>
#include <RWMesh_CoordinateSystemConverter.hxx>
#include <TCollection_AsciiString.hxx>
#include <XCAFPrs_Style.hxx>
#include <RWMesh_NodeAttributes.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TDocStd_Document.hxx>
#include <Message_ProgressIndicator.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <TDF_Label.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(RWMesh, mod) {

py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.XCAFPrs");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopAbs");

// ENUM: RWMESH_COORDINATESYSTEM
py::enum_<RWMesh_CoordinateSystem>(mod, "RWMesh_CoordinateSystem", "Standard coordinate system definition. Open CASCADE does not force application using specific coordinate system, although Draw Harness and samples define +Z-up +Y-forward coordinate system for camera view manipulation. This enumeration defines two commonly used conventions - Z-up and Y-up..")
	.value("RWMesh_CoordinateSystem_Undefined", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_Undefined)
	.value("RWMesh_CoordinateSystem_posYfwd_posZup", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_posYfwd_posZup)
	.value("RWMesh_CoordinateSystem_negZfwd_posYup", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_negZfwd_posYup)
	.value("RWMesh_CoordinateSystem_Blender", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_Blender)
	.value("RWMesh_CoordinateSystem_glTF", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_glTF)
	.value("RWMesh_CoordinateSystem_Zup", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_Zup)
	.value("RWMesh_CoordinateSystem_Yup", RWMesh_CoordinateSystem::RWMesh_CoordinateSystem_Yup)
	.export_values();


// ENUM: RWMESH_CAFREADERSTATUSEX
py::enum_<RWMesh_CafReaderStatusEx>(mod, "RWMesh_CafReaderStatusEx", "Extended status bits.")
	.value("RWMesh_CafReaderStatusEx_NONE", RWMesh_CafReaderStatusEx::RWMesh_CafReaderStatusEx_NONE)
	.value("RWMesh_CafReaderStatusEx_Partial", RWMesh_CafReaderStatusEx::RWMesh_CafReaderStatusEx_Partial)
	.export_values();


// CLASS: RWMESH_COORDINATESYSTEMCONVERTER
py::class_<RWMesh_CoordinateSystemConverter> cls_RWMesh_CoordinateSystemConverter(mod, "RWMesh_CoordinateSystemConverter", "Coordinate system converter defining the following tools: - Initialization for commonly used coordinate systems Z-up and Y-up. - Perform length unit conversion (scaling). - Conversion of three basic elements: a) mesh node Positions, b) mesh node Normals, c) model nodes Transformations (locations).");

// Constructors
cls_RWMesh_CoordinateSystemConverter.def(py::init<>());

// Methods
cls_RWMesh_CoordinateSystemConverter.def_static("StandardCoordinateSystem_", (gp_Ax3 (*)(RWMesh_CoordinateSystem)) &RWMesh_CoordinateSystemConverter::StandardCoordinateSystem, "Return a standard coordinate system definition.", py::arg("theSys"));
cls_RWMesh_CoordinateSystemConverter.def("IsEmpty", (Standard_Boolean (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::IsEmpty, "Return TRUE if there is no transformation (target and current coordinates systems are same).");
cls_RWMesh_CoordinateSystemConverter.def("InputLengthUnit", (Standard_Real (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::InputLengthUnit, "Return source length units, defined as scale factor to m (meters). -1.0 by default, which means that NO conversion will be applied (regardless output length unit).");
cls_RWMesh_CoordinateSystemConverter.def("SetInputLengthUnit", (void (RWMesh_CoordinateSystemConverter::*)(Standard_Real)) &RWMesh_CoordinateSystemConverter::SetInputLengthUnit, "Set source length units as scale factor to m (meters).", py::arg("theInputScale"));
cls_RWMesh_CoordinateSystemConverter.def("OutputLengthUnit", (Standard_Real (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::OutputLengthUnit, "Return destination length units, defined as scale factor to m (meters). -1.0 by default, which means that NO conversion will be applied (regardless input length unit).");
cls_RWMesh_CoordinateSystemConverter.def("SetOutputLengthUnit", (void (RWMesh_CoordinateSystemConverter::*)(Standard_Real)) &RWMesh_CoordinateSystemConverter::SetOutputLengthUnit, "Set destination length units as scale factor to m (meters).", py::arg("theOutputScale"));
cls_RWMesh_CoordinateSystemConverter.def("HasInputCoordinateSystem", (Standard_Boolean (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::HasInputCoordinateSystem, "Return TRUE if source coordinate system has been set; FALSE by default.");
cls_RWMesh_CoordinateSystemConverter.def("InputCoordinateSystem", (const gp_Ax3 & (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::InputCoordinateSystem, "Source coordinate system; UNDEFINED by default.");
cls_RWMesh_CoordinateSystemConverter.def("SetInputCoordinateSystem", (void (RWMesh_CoordinateSystemConverter::*)(const gp_Ax3 &)) &RWMesh_CoordinateSystemConverter::SetInputCoordinateSystem, "Set source coordinate system.", py::arg("theSysFrom"));
cls_RWMesh_CoordinateSystemConverter.def("SetInputCoordinateSystem", (void (RWMesh_CoordinateSystemConverter::*)(RWMesh_CoordinateSystem)) &RWMesh_CoordinateSystemConverter::SetInputCoordinateSystem, "Set source coordinate system.", py::arg("theSysFrom"));
cls_RWMesh_CoordinateSystemConverter.def("HasOutputCoordinateSystem", (Standard_Boolean (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::HasOutputCoordinateSystem, "Return TRUE if destination coordinate system has been set; FALSE by default.");
cls_RWMesh_CoordinateSystemConverter.def("OutputCoordinateSystem", (const gp_Ax3 & (RWMesh_CoordinateSystemConverter::*)() const) &RWMesh_CoordinateSystemConverter::OutputCoordinateSystem, "Destination coordinate system; UNDEFINED by default.");
cls_RWMesh_CoordinateSystemConverter.def("SetOutputCoordinateSystem", (void (RWMesh_CoordinateSystemConverter::*)(const gp_Ax3 &)) &RWMesh_CoordinateSystemConverter::SetOutputCoordinateSystem, "Set destination coordinate system.", py::arg("theSysTo"));
cls_RWMesh_CoordinateSystemConverter.def("SetOutputCoordinateSystem", (void (RWMesh_CoordinateSystemConverter::*)(RWMesh_CoordinateSystem)) &RWMesh_CoordinateSystemConverter::SetOutputCoordinateSystem, "Set destination coordinate system.", py::arg("theSysTo"));
cls_RWMesh_CoordinateSystemConverter.def("Init", (void (RWMesh_CoordinateSystemConverter::*)(const gp_Ax3 &, Standard_Real, const gp_Ax3 &, Standard_Real)) &RWMesh_CoordinateSystemConverter::Init, "Initialize transformation.", py::arg("theInputSystem"), py::arg("theInputLengthUnit"), py::arg("theOutputSystem"), py::arg("theOutputLengthUnit"));
cls_RWMesh_CoordinateSystemConverter.def("TransformTransformation", (void (RWMesh_CoordinateSystemConverter::*)(gp_Trsf &) const) &RWMesh_CoordinateSystemConverter::TransformTransformation, "Transform transformation.", py::arg("theTrsf"));
cls_RWMesh_CoordinateSystemConverter.def("TransformPosition", (void (RWMesh_CoordinateSystemConverter::*)(gp_XYZ &) const) &RWMesh_CoordinateSystemConverter::TransformPosition, "Transform position.", py::arg("thePos"));
cls_RWMesh_CoordinateSystemConverter.def("TransformNormal", (void (RWMesh_CoordinateSystemConverter::*)(Graphic3d_Vec3 &) const) &RWMesh_CoordinateSystemConverter::TransformNormal, "Transform normal (e.g. exclude translation/scale part of transformation).", py::arg("theNorm"));

// CLASS: RWMESH_NODEATTRIBUTES
py::class_<RWMesh_NodeAttributes> cls_RWMesh_NodeAttributes(mod, "RWMesh_NodeAttributes", "Attributes of the node.");

// Constructors
cls_RWMesh_NodeAttributes.def(py::init<>());

// Fields
cls_RWMesh_NodeAttributes.def_readwrite("Name", &RWMesh_NodeAttributes::Name, "name for the user");
cls_RWMesh_NodeAttributes.def_readwrite("RawName", &RWMesh_NodeAttributes::RawName, "name within low-level format structure");
cls_RWMesh_NodeAttributes.def_readwrite("Style", &RWMesh_NodeAttributes::Style, "presentation style");

// TYPEDEF: RWMESH_NODEATTRIBUTEMAP
bind_NCollection_DataMap<TopoDS_Shape, RWMesh_NodeAttributes, TopTools_ShapeMapHasher>(mod, "RWMesh_NodeAttributeMap", py::module_local(false));

// CLASS: RWMESH_CAFREADER
py::class_<RWMesh_CafReader, opencascade::handle<RWMesh_CafReader>, Standard_Transient> cls_RWMesh_CafReader(mod, "RWMesh_CafReader", "The general interface for importing mesh data into XDE document.");

// Methods
cls_RWMesh_CafReader.def_static("get_type_name_", (const char * (*)()) &RWMesh_CafReader::get_type_name, "None");
cls_RWMesh_CafReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWMesh_CafReader::get_type_descriptor, "None");
cls_RWMesh_CafReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::DynamicType, "None");
cls_RWMesh_CafReader.def("Document", (const opencascade::handle<TDocStd_Document> & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::Document, "Return target document.");
cls_RWMesh_CafReader.def("SetDocument", (void (RWMesh_CafReader::*)(const opencascade::handle<TDocStd_Document> &)) &RWMesh_CafReader::SetDocument, "Set target document.", py::arg("theDoc"));
cls_RWMesh_CafReader.def("RootPrefix", (const TCollection_AsciiString & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::RootPrefix, "Return prefix for generating root labels names.");
cls_RWMesh_CafReader.def("SetRootPrefix", (void (RWMesh_CafReader::*)(const TCollection_AsciiString &)) &RWMesh_CafReader::SetRootPrefix, "Set prefix for generating root labels names", py::arg("theRootPrefix"));
cls_RWMesh_CafReader.def("ToFillIncompleteDocument", (Standard_Boolean (RWMesh_CafReader::*)() const) &RWMesh_CafReader::ToFillIncompleteDocument, "Flag indicating if partially read file content should be put into the XDE document, TRUE by default.");
cls_RWMesh_CafReader.def("SetFillIncompleteDocument", (void (RWMesh_CafReader::*)(Standard_Boolean)) &RWMesh_CafReader::SetFillIncompleteDocument, "Set flag allowing partially read file content to be put into the XDE document.", py::arg("theToFillIncomplete"));
cls_RWMesh_CafReader.def("MemoryLimitMiB", (Standard_Integer (RWMesh_CafReader::*)() const) &RWMesh_CafReader::MemoryLimitMiB, "Return memory usage limit in MiB, -1 by default which means no limit.");
cls_RWMesh_CafReader.def("SetMemoryLimitMiB", (void (RWMesh_CafReader::*)(Standard_Integer)) &RWMesh_CafReader::SetMemoryLimitMiB, "Set memory usage limit in MiB; can be ignored by reader implementation!", py::arg("theLimitMiB"));
cls_RWMesh_CafReader.def("CoordinateSystemConverter", (const RWMesh_CoordinateSystemConverter & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::CoordinateSystemConverter, "Return coordinate system converter.");
cls_RWMesh_CafReader.def("SetCoordinateSystemConverter", (void (RWMesh_CafReader::*)(const RWMesh_CoordinateSystemConverter &)) &RWMesh_CafReader::SetCoordinateSystemConverter, "Set coordinate system converter.", py::arg("theConverter"));
cls_RWMesh_CafReader.def("SystemLengthUnit", (Standard_Real (RWMesh_CafReader::*)() const) &RWMesh_CafReader::SystemLengthUnit, "Return the length unit to convert into while reading the file, defined as scale factor for m (meters); -1.0 by default, which means that NO conversion will be applied.");
cls_RWMesh_CafReader.def("SetSystemLengthUnit", (void (RWMesh_CafReader::*)(Standard_Real)) &RWMesh_CafReader::SetSystemLengthUnit, "Set system length units to convert into while reading the file, defined as scale factor for m (meters).", py::arg("theUnits"));
cls_RWMesh_CafReader.def("HasSystemCoordinateSystem", (Standard_Boolean (RWMesh_CafReader::*)() const) &RWMesh_CafReader::HasSystemCoordinateSystem, "Return TRUE if system coordinate system has been defined; FALSE by default.");
cls_RWMesh_CafReader.def("SystemCoordinateSystem", (const gp_Ax3 & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::SystemCoordinateSystem, "Return system coordinate system; UNDEFINED by default, which means that no conversion will be done.");
cls_RWMesh_CafReader.def("SetSystemCoordinateSystem", (void (RWMesh_CafReader::*)(const gp_Ax3 &)) &RWMesh_CafReader::SetSystemCoordinateSystem, "Set system origin coordinate system to perform conversion into during read.", py::arg("theCS"));
cls_RWMesh_CafReader.def("SetSystemCoordinateSystem", (void (RWMesh_CafReader::*)(RWMesh_CoordinateSystem)) &RWMesh_CafReader::SetSystemCoordinateSystem, "Set system origin coordinate system to perform conversion into during read.", py::arg("theCS"));
cls_RWMesh_CafReader.def("FileLengthUnit", (Standard_Real (RWMesh_CafReader::*)() const) &RWMesh_CafReader::FileLengthUnit, "Return the length unit to convert from while reading the file, defined as scale factor for m (meters). Can be undefined (-1.0) if file format is unitless.");
cls_RWMesh_CafReader.def("SetFileLengthUnit", (void (RWMesh_CafReader::*)(Standard_Real)) &RWMesh_CafReader::SetFileLengthUnit, "Set (override) file length units to convert from while reading the file, defined as scale factor for m (meters).", py::arg("theUnits"));
cls_RWMesh_CafReader.def("HasFileCoordinateSystem", (Standard_Boolean (RWMesh_CafReader::*)() const) &RWMesh_CafReader::HasFileCoordinateSystem, "Return TRUE if file origin coordinate system has been defined.");
cls_RWMesh_CafReader.def("FileCoordinateSystem", (const gp_Ax3 & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::FileCoordinateSystem, "Return file origin coordinate system; can be UNDEFINED, which means no conversion will be done.");
cls_RWMesh_CafReader.def("SetFileCoordinateSystem", (void (RWMesh_CafReader::*)(const gp_Ax3 &)) &RWMesh_CafReader::SetFileCoordinateSystem, "Set (override) file origin coordinate system to perform conversion during read.", py::arg("theCS"));
cls_RWMesh_CafReader.def("SetFileCoordinateSystem", (void (RWMesh_CafReader::*)(RWMesh_CoordinateSystem)) &RWMesh_CafReader::SetFileCoordinateSystem, "Set (override) file origin coordinate system to perform conversion during read.", py::arg("theCS"));
cls_RWMesh_CafReader.def("Perform", (bool (RWMesh_CafReader::*)(const TCollection_AsciiString &, const opencascade::handle<Message_ProgressIndicator> &)) &RWMesh_CafReader::Perform, "Read the data from specified file. The Document instance should be set beforehand.", py::arg("theFile"), py::arg("theProgress"));
cls_RWMesh_CafReader.def("ExtraStatus", (Standard_Integer (RWMesh_CafReader::*)() const) &RWMesh_CafReader::ExtraStatus, "Return extended status flags.");
cls_RWMesh_CafReader.def("SingleShape", (TopoDS_Shape (RWMesh_CafReader::*)() const) &RWMesh_CafReader::SingleShape, "Return result as a single shape.");
cls_RWMesh_CafReader.def("ExternalFiles", (const NCollection_IndexedMap<TCollection_AsciiString> & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::ExternalFiles, "Return the list of complementary files - external references (textures, data, etc.).");
cls_RWMesh_CafReader.def("Metadata", (const TColStd_IndexedDataMapOfStringString & (RWMesh_CafReader::*)() const) &RWMesh_CafReader::Metadata, "Return metadata map.");
cls_RWMesh_CafReader.def("ProbeHeader", [](RWMesh_CafReader &self, const TCollection_AsciiString & a0) -> Standard_Boolean { return self.ProbeHeader(a0); });
cls_RWMesh_CafReader.def("ProbeHeader", (Standard_Boolean (RWMesh_CafReader::*)(const TCollection_AsciiString &, const opencascade::handle<Message_ProgressIndicator> &)) &RWMesh_CafReader::ProbeHeader, "Read the header data from specified file without reading entire model. The main purpose is collecting metadata and external references - for copying model into a new location, for example. Can be NOT implemented (unsupported by format / reader).", py::arg("theFile"), py::arg("theProgress"));


}
