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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlMDataXtd_AxisDriver.hxx>
#include <XmlMDataXtd_ShapeDriver.hxx>
#include <XmlMDataXtd_PointDriver.hxx>
#include <XmlMDataXtd_PlaneDriver.hxx>
#include <XmlMDataXtd_GeometryDriver.hxx>
#include <XmlMDataXtd_ConstraintDriver.hxx>
#include <XmlMDataXtd_PlacementDriver.hxx>
#include <XmlMDataXtd_PatternStdDriver.hxx>
#include <XmlMDataXtd_TriangulationDriver.hxx>
#include <XmlMDataXtd.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <XmlMDataXtd_PositionDriver.hxx>
#include <XmlMDataXtd_PresentationDriver.hxx>
#include <Standard_IStream.hxx>

PYBIND11_MODULE(XmlMDataXtd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

// CLASS: XMLMDATAXTD
py::class_<XmlMDataXtd> cls_XmlMDataXtd(mod, "XmlMDataXtd", "Storage and Retrieval drivers for modelling attributes. Transient attributes are defined in package TDataXtd.");

// Methods
// cls_XmlMDataXtd.def_static("operator new_", (void * (*)(size_t)) &XmlMDataXtd::operator new, "None", py::arg("theSize"));
// cls_XmlMDataXtd.def_static("operator delete_", (void (*)(void *)) &XmlMDataXtd::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDataXtd.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDataXtd::operator new[], "None", py::arg("theSize"));
// cls_XmlMDataXtd.def_static("operator delete[]_", (void (*)(void *)) &XmlMDataXtd::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDataXtd.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDataXtd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDataXtd.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDataXtd::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDataXtd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDataXtd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("anMsgDrv"));
cls_XmlMDataXtd.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &XmlMDataXtd::SetDocumentVersion, "None", py::arg("DocVersion"));
cls_XmlMDataXtd.def_static("DocumentVersion_", (Standard_Integer (*)()) &XmlMDataXtd::DocumentVersion, "None");

// CLASS: XMLMDATAXTD_AXISDRIVER
py::class_<XmlMDataXtd_AxisDriver, opencascade::handle<XmlMDataXtd_AxisDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_AxisDriver(mod, "XmlMDataXtd_AxisDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_AxisDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_AxisDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_AxisDriver::*)() const) &XmlMDataXtd_AxisDriver::NewEmpty, "None");
cls_XmlMDataXtd_AxisDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_AxisDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_AxisDriver.def("Paste", (void (XmlMDataXtd_AxisDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_AxisDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_AxisDriver::get_type_name, "None");
cls_XmlMDataXtd_AxisDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_AxisDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_AxisDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_AxisDriver::*)() const) &XmlMDataXtd_AxisDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_CONSTRAINTDRIVER
py::class_<XmlMDataXtd_ConstraintDriver, opencascade::handle<XmlMDataXtd_ConstraintDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_ConstraintDriver(mod, "XmlMDataXtd_ConstraintDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_ConstraintDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_ConstraintDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_ConstraintDriver::*)() const) &XmlMDataXtd_ConstraintDriver::NewEmpty, "None");
cls_XmlMDataXtd_ConstraintDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_ConstraintDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_ConstraintDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_ConstraintDriver.def("Paste", (void (XmlMDataXtd_ConstraintDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_ConstraintDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_ConstraintDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_ConstraintDriver::get_type_name, "None");
cls_XmlMDataXtd_ConstraintDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_ConstraintDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_ConstraintDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_ConstraintDriver::*)() const) &XmlMDataXtd_ConstraintDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_GEOMETRYDRIVER
py::class_<XmlMDataXtd_GeometryDriver, opencascade::handle<XmlMDataXtd_GeometryDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_GeometryDriver(mod, "XmlMDataXtd_GeometryDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_GeometryDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_GeometryDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_GeometryDriver::*)() const) &XmlMDataXtd_GeometryDriver::NewEmpty, "None");
cls_XmlMDataXtd_GeometryDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_GeometryDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_GeometryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_GeometryDriver.def("Paste", (void (XmlMDataXtd_GeometryDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_GeometryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_GeometryDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_GeometryDriver::get_type_name, "None");
cls_XmlMDataXtd_GeometryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_GeometryDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_GeometryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_GeometryDriver::*)() const) &XmlMDataXtd_GeometryDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_PATTERNSTDDRIVER
py::class_<XmlMDataXtd_PatternStdDriver, opencascade::handle<XmlMDataXtd_PatternStdDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PatternStdDriver(mod, "XmlMDataXtd_PatternStdDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PatternStdDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PatternStdDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PatternStdDriver::*)() const) &XmlMDataXtd_PatternStdDriver::NewEmpty, "None");
cls_XmlMDataXtd_PatternStdDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PatternStdDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PatternStdDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PatternStdDriver.def("Paste", (void (XmlMDataXtd_PatternStdDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PatternStdDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PatternStdDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PatternStdDriver::get_type_name, "None");
cls_XmlMDataXtd_PatternStdDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PatternStdDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PatternStdDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PatternStdDriver::*)() const) &XmlMDataXtd_PatternStdDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_PLACEMENTDRIVER
py::class_<XmlMDataXtd_PlacementDriver, opencascade::handle<XmlMDataXtd_PlacementDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PlacementDriver(mod, "XmlMDataXtd_PlacementDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PlacementDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PlacementDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PlacementDriver::*)() const) &XmlMDataXtd_PlacementDriver::NewEmpty, "None");
cls_XmlMDataXtd_PlacementDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PlacementDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PlacementDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlacementDriver.def("Paste", (void (XmlMDataXtd_PlacementDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PlacementDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlacementDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PlacementDriver::get_type_name, "None");
cls_XmlMDataXtd_PlacementDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PlacementDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PlacementDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PlacementDriver::*)() const) &XmlMDataXtd_PlacementDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_PLANEDRIVER
py::class_<XmlMDataXtd_PlaneDriver, opencascade::handle<XmlMDataXtd_PlaneDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PlaneDriver(mod, "XmlMDataXtd_PlaneDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PlaneDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PlaneDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PlaneDriver::*)() const) &XmlMDataXtd_PlaneDriver::NewEmpty, "None");
cls_XmlMDataXtd_PlaneDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PlaneDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlaneDriver.def("Paste", (void (XmlMDataXtd_PlaneDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlaneDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PlaneDriver::get_type_name, "None");
cls_XmlMDataXtd_PlaneDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PlaneDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PlaneDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PlaneDriver::*)() const) &XmlMDataXtd_PlaneDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_POINTDRIVER
py::class_<XmlMDataXtd_PointDriver, opencascade::handle<XmlMDataXtd_PointDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PointDriver(mod, "XmlMDataXtd_PointDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PointDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PointDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PointDriver::*)() const) &XmlMDataXtd_PointDriver::NewEmpty, "None");
cls_XmlMDataXtd_PointDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PointDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PointDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PointDriver.def("Paste", (void (XmlMDataXtd_PointDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PointDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PointDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PointDriver::get_type_name, "None");
cls_XmlMDataXtd_PointDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PointDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PointDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PointDriver::*)() const) &XmlMDataXtd_PointDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_POSITIONDRIVER
py::class_<XmlMDataXtd_PositionDriver, opencascade::handle<XmlMDataXtd_PositionDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PositionDriver(mod, "XmlMDataXtd_PositionDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PositionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PositionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PositionDriver::*)() const) &XmlMDataXtd_PositionDriver::NewEmpty, "None");
cls_XmlMDataXtd_PositionDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PositionDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PositionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PositionDriver.def("Paste", (void (XmlMDataXtd_PositionDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PositionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PositionDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PositionDriver::get_type_name, "None");
cls_XmlMDataXtd_PositionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PositionDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PositionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PositionDriver::*)() const) &XmlMDataXtd_PositionDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_PRESENTATIONDRIVER
py::class_<XmlMDataXtd_PresentationDriver, opencascade::handle<XmlMDataXtd_PresentationDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PresentationDriver(mod, "XmlMDataXtd_PresentationDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PresentationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_PresentationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PresentationDriver::*)() const) &XmlMDataXtd_PresentationDriver::NewEmpty, "None");
cls_XmlMDataXtd_PresentationDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PresentationDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PresentationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PresentationDriver.def("Paste", (void (XmlMDataXtd_PresentationDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PresentationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PresentationDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PresentationDriver::get_type_name, "None");
cls_XmlMDataXtd_PresentationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PresentationDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PresentationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PresentationDriver::*)() const) &XmlMDataXtd_PresentationDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_SHAPEDRIVER
py::class_<XmlMDataXtd_ShapeDriver, opencascade::handle<XmlMDataXtd_ShapeDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_ShapeDriver(mod, "XmlMDataXtd_ShapeDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_ShapeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_ShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_ShapeDriver::*)() const) &XmlMDataXtd_ShapeDriver::NewEmpty, "None");
cls_XmlMDataXtd_ShapeDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_ShapeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_ShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_ShapeDriver.def("Paste", (void (XmlMDataXtd_ShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_ShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_ShapeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_ShapeDriver::get_type_name, "None");
cls_XmlMDataXtd_ShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_ShapeDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_ShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_ShapeDriver::*)() const) &XmlMDataXtd_ShapeDriver::DynamicType, "None");

// CLASS: XMLMDATAXTD_TRIANGULATIONDRIVER
py::class_<XmlMDataXtd_TriangulationDriver, opencascade::handle<XmlMDataXtd_TriangulationDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_TriangulationDriver(mod, "XmlMDataXtd_TriangulationDriver", "TDataStd_Mesh attribute XML Driver.");

// Constructors
cls_XmlMDataXtd_TriangulationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataXtd_TriangulationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_TriangulationDriver::*)() const) &XmlMDataXtd_TriangulationDriver::NewEmpty, "None");
cls_XmlMDataXtd_TriangulationDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_TriangulationDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_TriangulationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_TriangulationDriver.def("Paste", (void (XmlMDataXtd_TriangulationDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_TriangulationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_TriangulationDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_TriangulationDriver::get_type_name, "None");
cls_XmlMDataXtd_TriangulationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_TriangulationDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_TriangulationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_TriangulationDriver::*)() const) &XmlMDataXtd_TriangulationDriver::DynamicType, "None");


}
