/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <BinMDataXtd_PointDriver.hxx>
#include <BinMDataXtd_AxisDriver.hxx>
#include <BinMDataXtd_PlaneDriver.hxx>
#include <BinMDataXtd_GeometryDriver.hxx>
#include <BinMDataXtd_ConstraintDriver.hxx>
#include <BinMDataXtd_PlacementDriver.hxx>
#include <BinMDataXtd_PatternStdDriver.hxx>
#include <BinMDataXtd_ShapeDriver.hxx>
#include <BinMDataXtd_TriangulationDriver.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <BinMDataXtd.hxx>
#include <BinMDataXtd_PositionDriver.hxx>
#include <BinMDataXtd_PresentationDriver.hxx>

PYBIND11_MODULE(BinMDataXtd, mod) {

	// IMPORT
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.BinObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PointDriver.hxx
	py::class_<BinMDataXtd_PointDriver, opencascade::handle<BinMDataXtd_PointDriver>, BinMDF_ADriver> cls_BinMDataXtd_PointDriver(mod, "BinMDataXtd_PointDriver", "Point attribute Driver.");
	cls_BinMDataXtd_PointDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PointDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PointDriver::*)() const ) &BinMDataXtd_PointDriver::NewEmpty, "None");
	cls_BinMDataXtd_PointDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PointDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PointDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PointDriver.def("Paste", (void (BinMDataXtd_PointDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PointDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PointDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PointDriver::get_type_name, "None");
	cls_BinMDataXtd_PointDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PointDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PointDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PointDriver::*)() const ) &BinMDataXtd_PointDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_AxisDriver.hxx
	py::class_<BinMDataXtd_AxisDriver, opencascade::handle<BinMDataXtd_AxisDriver>, BinMDF_ADriver> cls_BinMDataXtd_AxisDriver(mod, "BinMDataXtd_AxisDriver", "Axis attribute Driver.");
	cls_BinMDataXtd_AxisDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_AxisDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_AxisDriver::*)() const ) &BinMDataXtd_AxisDriver::NewEmpty, "None");
	cls_BinMDataXtd_AxisDriver.def("Paste", (Standard_Boolean (BinMDataXtd_AxisDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_AxisDriver.def("Paste", (void (BinMDataXtd_AxisDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_AxisDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_AxisDriver::get_type_name, "None");
	cls_BinMDataXtd_AxisDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_AxisDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_AxisDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_AxisDriver::*)() const ) &BinMDataXtd_AxisDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PlaneDriver.hxx
	py::class_<BinMDataXtd_PlaneDriver, opencascade::handle<BinMDataXtd_PlaneDriver>, BinMDF_ADriver> cls_BinMDataXtd_PlaneDriver(mod, "BinMDataXtd_PlaneDriver", "Plane attribute Driver.");
	cls_BinMDataXtd_PlaneDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PlaneDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PlaneDriver::*)() const ) &BinMDataXtd_PlaneDriver::NewEmpty, "None");
	cls_BinMDataXtd_PlaneDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PlaneDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PlaneDriver.def("Paste", (void (BinMDataXtd_PlaneDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PlaneDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PlaneDriver::get_type_name, "None");
	cls_BinMDataXtd_PlaneDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PlaneDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PlaneDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PlaneDriver::*)() const ) &BinMDataXtd_PlaneDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_GeometryDriver.hxx
	py::class_<BinMDataXtd_GeometryDriver, opencascade::handle<BinMDataXtd_GeometryDriver>, BinMDF_ADriver> cls_BinMDataXtd_GeometryDriver(mod, "BinMDataXtd_GeometryDriver", "Attribute Driver.");
	cls_BinMDataXtd_GeometryDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_GeometryDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_GeometryDriver::*)() const ) &BinMDataXtd_GeometryDriver::NewEmpty, "None");
	cls_BinMDataXtd_GeometryDriver.def("Paste", (Standard_Boolean (BinMDataXtd_GeometryDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_GeometryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_GeometryDriver.def("Paste", (void (BinMDataXtd_GeometryDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_GeometryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_GeometryDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_GeometryDriver::get_type_name, "None");
	cls_BinMDataXtd_GeometryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_GeometryDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_GeometryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_GeometryDriver::*)() const ) &BinMDataXtd_GeometryDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_ConstraintDriver.hxx
	py::class_<BinMDataXtd_ConstraintDriver, opencascade::handle<BinMDataXtd_ConstraintDriver>, BinMDF_ADriver> cls_BinMDataXtd_ConstraintDriver(mod, "BinMDataXtd_ConstraintDriver", "Attribute Driver.");
	cls_BinMDataXtd_ConstraintDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_ConstraintDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_ConstraintDriver::*)() const ) &BinMDataXtd_ConstraintDriver::NewEmpty, "None");
	cls_BinMDataXtd_ConstraintDriver.def("Paste", (Standard_Boolean (BinMDataXtd_ConstraintDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_ConstraintDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_ConstraintDriver.def("Paste", (void (BinMDataXtd_ConstraintDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_ConstraintDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_ConstraintDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_ConstraintDriver::get_type_name, "None");
	cls_BinMDataXtd_ConstraintDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_ConstraintDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_ConstraintDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_ConstraintDriver::*)() const ) &BinMDataXtd_ConstraintDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PlacementDriver.hxx
	py::class_<BinMDataXtd_PlacementDriver, opencascade::handle<BinMDataXtd_PlacementDriver>, BinMDF_ADriver> cls_BinMDataXtd_PlacementDriver(mod, "BinMDataXtd_PlacementDriver", "Placement attribute Driver.");
	cls_BinMDataXtd_PlacementDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PlacementDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PlacementDriver::*)() const ) &BinMDataXtd_PlacementDriver::NewEmpty, "None");
	cls_BinMDataXtd_PlacementDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PlacementDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PlacementDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PlacementDriver.def("Paste", (void (BinMDataXtd_PlacementDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PlacementDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PlacementDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PlacementDriver::get_type_name, "None");
	cls_BinMDataXtd_PlacementDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PlacementDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PlacementDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PlacementDriver::*)() const ) &BinMDataXtd_PlacementDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PatternStdDriver.hxx
	py::class_<BinMDataXtd_PatternStdDriver, opencascade::handle<BinMDataXtd_PatternStdDriver>, BinMDF_ADriver> cls_BinMDataXtd_PatternStdDriver(mod, "BinMDataXtd_PatternStdDriver", "Attribute Driver.");
	cls_BinMDataXtd_PatternStdDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PatternStdDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PatternStdDriver::*)() const ) &BinMDataXtd_PatternStdDriver::NewEmpty, "None");
	cls_BinMDataXtd_PatternStdDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PatternStdDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PatternStdDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PatternStdDriver.def("Paste", (void (BinMDataXtd_PatternStdDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PatternStdDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PatternStdDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PatternStdDriver::get_type_name, "None");
	cls_BinMDataXtd_PatternStdDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PatternStdDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PatternStdDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PatternStdDriver::*)() const ) &BinMDataXtd_PatternStdDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_ShapeDriver.hxx
	py::class_<BinMDataXtd_ShapeDriver, opencascade::handle<BinMDataXtd_ShapeDriver>, BinMDF_ADriver> cls_BinMDataXtd_ShapeDriver(mod, "BinMDataXtd_ShapeDriver", "Shape attribute Driver.");
	cls_BinMDataXtd_ShapeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_ShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_ShapeDriver::*)() const ) &BinMDataXtd_ShapeDriver::NewEmpty, "None");
	cls_BinMDataXtd_ShapeDriver.def("Paste", (Standard_Boolean (BinMDataXtd_ShapeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_ShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_ShapeDriver.def("Paste", (void (BinMDataXtd_ShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_ShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_ShapeDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_ShapeDriver::get_type_name, "None");
	cls_BinMDataXtd_ShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_ShapeDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_ShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_ShapeDriver::*)() const ) &BinMDataXtd_ShapeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_TriangulationDriver.hxx
	py::class_<BinMDataXtd_TriangulationDriver, opencascade::handle<BinMDataXtd_TriangulationDriver>, BinMDF_ADriver> cls_BinMDataXtd_TriangulationDriver(mod, "BinMDataXtd_TriangulationDriver", "TDataXtd_Triangulation attribute bin Driver.");
	cls_BinMDataXtd_TriangulationDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_TriangulationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_TriangulationDriver::*)() const ) &BinMDataXtd_TriangulationDriver::NewEmpty, "None");
	cls_BinMDataXtd_TriangulationDriver.def("Paste", (Standard_Boolean (BinMDataXtd_TriangulationDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_TriangulationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_TriangulationDriver.def("Paste", (void (BinMDataXtd_TriangulationDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_TriangulationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_TriangulationDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_TriangulationDriver::get_type_name, "None");
	cls_BinMDataXtd_TriangulationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_TriangulationDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_TriangulationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_TriangulationDriver::*)() const ) &BinMDataXtd_TriangulationDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd.hxx
	py::class_<BinMDataXtd, std::unique_ptr<BinMDataXtd, Deleter<BinMDataXtd>>> cls_BinMDataXtd(mod, "BinMDataXtd", "Storage and Retrieval drivers for modelling attributes.");
	cls_BinMDataXtd.def(py::init<>());
	cls_BinMDataXtd.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMDataXtd::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));
	cls_BinMDataXtd.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &BinMDataXtd::SetDocumentVersion, "None", py::arg("DocVersion"));
	cls_BinMDataXtd.def_static("DocumentVersion_", (Standard_Integer (*)()) &BinMDataXtd::DocumentVersion, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PositionDriver.hxx
	py::class_<BinMDataXtd_PositionDriver, opencascade::handle<BinMDataXtd_PositionDriver>, BinMDF_ADriver> cls_BinMDataXtd_PositionDriver(mod, "BinMDataXtd_PositionDriver", "Position Attribute Driver.");
	cls_BinMDataXtd_PositionDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PositionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PositionDriver::*)() const ) &BinMDataXtd_PositionDriver::NewEmpty, "None");
	cls_BinMDataXtd_PositionDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PositionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PositionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PositionDriver.def("Paste", (void (BinMDataXtd_PositionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PositionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PositionDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PositionDriver::get_type_name, "None");
	cls_BinMDataXtd_PositionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PositionDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PositionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PositionDriver::*)() const ) &BinMDataXtd_PositionDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataXtd_PresentationDriver.hxx
	py::class_<BinMDataXtd_PresentationDriver, opencascade::handle<BinMDataXtd_PresentationDriver>, BinMDF_ADriver> cls_BinMDataXtd_PresentationDriver(mod, "BinMDataXtd_PresentationDriver", "Presentation Attribute Driver.");
	cls_BinMDataXtd_PresentationDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataXtd_PresentationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_PresentationDriver::*)() const ) &BinMDataXtd_PresentationDriver::NewEmpty, "None");
	cls_BinMDataXtd_PresentationDriver.def("Paste", (Standard_Boolean (BinMDataXtd_PresentationDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataXtd_PresentationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PresentationDriver.def("Paste", (void (BinMDataXtd_PresentationDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataXtd_PresentationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataXtd_PresentationDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_PresentationDriver::get_type_name, "None");
	cls_BinMDataXtd_PresentationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_PresentationDriver::get_type_descriptor, "None");
	cls_BinMDataXtd_PresentationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_PresentationDriver::*)() const ) &BinMDataXtd_PresentationDriver::DynamicType, "None");


}
