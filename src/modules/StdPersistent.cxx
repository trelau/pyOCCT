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
#include <bind_StdObjMgt_Attribute.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <Standard_Transient.hxx>
#include <ShapePersistent_TopoDS.hxx>
#include <Standard_Handle.hxx>
#include <StdPersistent_TopoDS.hxx>
#include <Standard_Type.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_TShape.hxx>
#include <NCollection_Array1.hxx>
#include <StdObject_Shape.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StdPersistent_HArray1.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdPersistent.hxx>
#include <StdLPersistent_Void.hxx>
#include <StdPersistent_DataXtd.hxx>
#include <TDataXtd_Shape.hxx>
#include <TDataXtd_Point.hxx>
#include <TDataXtd_Axis.hxx>
#include <TDataXtd_Plane.hxx>
#include <TDataXtd_Placement.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TDataXtd_Geometry.hxx>
#include <TDataXtd_Position.hxx>
#include <gp_Pnt.hxx>
#include <TDataXtd_Constraint.hxx>
#include <StdPersistent_DataXtd_Constraint.hxx>
#include <TDataXtd_PatternStd.hxx>
#include <StdPersistent_DataXtd_PatternStd.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_Name.hxx>
#include <TDF_Data.hxx>
#include <StdPersistent_Naming.hxx>
#include <StdLPersistent_HString.hxx>
#include <TNaming_Naming.hxx>
#include <TDataXtd_Presentation.hxx>
#include <StdPersistent_PPrsStd.hxx>
#include <TopLoc_Datum3D.hxx>
#include <StdPersistent_TopLoc.hxx>
#include <TopLoc_Location.hxx>
#include <StdObject_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

PYBIND11_MODULE(StdPersistent, mod) {

py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StdObject");
py::module::import("OCCT.StdLPersistent");
py::module::import("OCCT.TDataXtd");
py::module::import("OCCT.gp");
py::module::import("OCCT.TNaming");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopLoc");

// CLASS: STDPERSISTENT_TOPODS
py::class_<StdPersistent_TopoDS> cls_StdPersistent_TopoDS(mod, "StdPersistent_TopoDS", "None");

// CLASS: STDPERSISTENT_HARRAY1OFSHAPE1
py::class_<StdPersistent_HArray1OfShape1, opencascade::handle<StdPersistent_HArray1OfShape1>, Standard_Transient> cls_StdPersistent_HArray1OfShape1(mod, "StdPersistent_HArray1OfShape1", "None", py::multiple_inheritance());

// Constructors
cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<StdObject_Shape>::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StdPersistent_HArray1OfShape1.def(py::init<const NCollection_Array1<StdObject_Shape> &>(), py::arg("theOther"));

// Methods
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg("theSize"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new[]_", (void * (*)(size_t)) &StdPersistent_HArray1OfShape1::operator new[], "None", py::arg("theSize"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete[]_", (void (*)(void *)) &StdPersistent_HArray1OfShape1::operator delete[], "None", py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t, void *)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *, void *)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdPersistent_HArray1OfShape1.def("Array1", (const NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)() const) &StdPersistent_HArray1OfShape1::Array1, "None");
cls_StdPersistent_HArray1OfShape1.def("ChangeArray1", (NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)()) &StdPersistent_HArray1OfShape1::ChangeArray1, "None");
cls_StdPersistent_HArray1OfShape1.def_static("get_type_name_", (const char * (*)()) &StdPersistent_HArray1OfShape1::get_type_name, "None");
cls_StdPersistent_HArray1OfShape1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdPersistent_HArray1OfShape1::get_type_descriptor, "None");
cls_StdPersistent_HArray1OfShape1.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdPersistent_HArray1OfShape1::*)() const) &StdPersistent_HArray1OfShape1::DynamicType, "None");

// CLASS: STDPERSISTENT_HARRAY1
py::class_<StdPersistent_HArray1> cls_StdPersistent_HArray1(mod, "StdPersistent_HArray1", "None");

// CLASS: STDPERSISTENT
py::class_<StdPersistent> cls_StdPersistent(mod, "StdPersistent", "None");

// Methods
cls_StdPersistent.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdPersistent::BindTypes, "Register types.", py::arg("theMap"));

// CLASS: STDPERSISTENT_DATAXTD
py::class_<StdPersistent_DataXtd> cls_StdPersistent_DataXtd(mod, "StdPersistent_DataXtd", "None");

// CLASS: STDPERSISTENT_DATAXTD_CONSTRAINT
bind_StdObjMgt_Attribute<TDataXtd_Constraint>(mod, "StdObjMgt_Attribute_TDataXtd_Constraint", py::module_local());

py::class_<StdPersistent_DataXtd_Constraint, opencascade::handle<StdPersistent_DataXtd_Constraint>, StdObjMgt_Attribute<TDataXtd_Constraint>> cls_StdPersistent_DataXtd_Constraint(mod, "StdPersistent_DataXtd_Constraint", "None");

// Methods
cls_StdPersistent_DataXtd_Constraint.def("Read", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_Constraint::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdPersistent_DataXtd_Constraint.def("Write", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_WriteData &) const) &StdPersistent_DataXtd_Constraint::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdPersistent_DataXtd_Constraint.def("PChildren", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdPersistent_DataXtd_Constraint::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdPersistent_DataXtd_Constraint.def("PName", (Standard_CString (StdPersistent_DataXtd_Constraint::*)() const) &StdPersistent_DataXtd_Constraint::PName, "Returns persistent type name");
// cls_StdPersistent_DataXtd_Constraint.def("Import", (void (StdPersistent_DataXtd_Constraint::*)(const opencascade::handle<TDataXtd_Constraint> &) const) &StdPersistent_DataXtd_Constraint::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDPERSISTENT_DATAXTD_PATTERNSTD
bind_StdObjMgt_Attribute<TDataXtd_PatternStd>(mod, "StdObjMgt_Attribute_TDataXtd_PatternStd", py::module_local());

py::class_<StdPersistent_DataXtd_PatternStd, opencascade::handle<StdPersistent_DataXtd_PatternStd>, StdObjMgt_Attribute<TDataXtd_PatternStd>> cls_StdPersistent_DataXtd_PatternStd(mod, "StdPersistent_DataXtd_PatternStd", "None");

// Methods
cls_StdPersistent_DataXtd_PatternStd.def("Read", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_PatternStd::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdPersistent_DataXtd_PatternStd.def("Write", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_WriteData &)) &StdPersistent_DataXtd_PatternStd::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdPersistent_DataXtd_PatternStd.def("PChildren", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdPersistent_DataXtd_PatternStd::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdPersistent_DataXtd_PatternStd.def("PName", (Standard_CString (StdPersistent_DataXtd_PatternStd::*)() const) &StdPersistent_DataXtd_PatternStd::PName, "Returns persistent type name");
// cls_StdPersistent_DataXtd_PatternStd.def("Import", (void (StdPersistent_DataXtd_PatternStd::*)(const opencascade::handle<TDataXtd_PatternStd> &) const) &StdPersistent_DataXtd_PatternStd::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDPERSISTENT_NAMING
py::class_<StdPersistent_Naming> cls_StdPersistent_Naming(mod, "StdPersistent_Naming", "None");

// CLASS: STDPERSISTENT_PPRSSTD
py::class_<StdPersistent_PPrsStd> cls_StdPersistent_PPrsStd(mod, "StdPersistent_PPrsStd", "None");

// CLASS: STDPERSISTENT_TOPLOC
py::class_<StdPersistent_TopLoc> cls_StdPersistent_TopLoc(mod, "StdPersistent_TopLoc", "None");

// Methods
// cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<ItemLocation> (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theLoc"), py::arg("theMap"));
// cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<Datum3D> (*)(const opencascade::handle<TopLoc_Datum3D> &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theDatum"), py::arg("theMap"));


}
