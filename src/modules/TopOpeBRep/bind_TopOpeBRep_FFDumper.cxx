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
#include <TopOpeBRep_FacesFiller.hxx>
#include <Standard_Transient.hxx>
#include <TopOpeBRep_PFacesFiller.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRep_FFDumper.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>

void bind_TopOpeBRep_FFDumper(py::module &mod){

py::class_<TopOpeBRep_FFDumper, opencascade::handle<TopOpeBRep_FFDumper>, Standard_Transient> cls_TopOpeBRep_FFDumper(mod, "TopOpeBRep_FFDumper", "None");

// Constructors
cls_TopOpeBRep_FFDumper.def(py::init<const TopOpeBRep_PFacesFiller &>(), py::arg("PFF"));

// Fields

// Methods
cls_TopOpeBRep_FFDumper.def("Init", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_PFacesFiller &)) &TopOpeBRep_FFDumper::Init, "None", py::arg("PFF"));
cls_TopOpeBRep_FFDumper.def("DumpLine", (void (TopOpeBRep_FFDumper::*)(const Standard_Integer)) &TopOpeBRep_FFDumper::DumpLine, "None", py::arg("I"));
cls_TopOpeBRep_FFDumper.def("DumpLine", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_FFDumper::DumpLine, "None", py::arg("L"));
cls_TopOpeBRep_FFDumper.def("DumpVP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_FFDumper::DumpVP, "None", py::arg("VP"));
cls_TopOpeBRep_FFDumper.def("DumpVP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &, const Standard_Integer)) &TopOpeBRep_FFDumper::DumpVP, "None", py::arg("VP"), py::arg("ISI"));
cls_TopOpeBRep_FFDumper.def("ExploreIndex", (Standard_Integer (TopOpeBRep_FFDumper::*)(const TopoDS_Shape &, const Standard_Integer) const) &TopOpeBRep_FFDumper::ExploreIndex, "None", py::arg("S"), py::arg("ISI"));
cls_TopOpeBRep_FFDumper.def("DumpDSP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean) const) &TopOpeBRep_FFDumper::DumpDSP, "None", py::arg("VP"), py::arg("GK"), py::arg("G"), py::arg("newinDS"));
cls_TopOpeBRep_FFDumper.def("PFacesFillerDummy", (TopOpeBRep_PFacesFiller (TopOpeBRep_FFDumper::*)() const) &TopOpeBRep_FFDumper::PFacesFillerDummy, "None");
cls_TopOpeBRep_FFDumper.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_FFDumper::get_type_name, "None");
cls_TopOpeBRep_FFDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_FFDumper::get_type_descriptor, "None");
cls_TopOpeBRep_FFDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_FFDumper::*)() const) &TopOpeBRep_FFDumper::DynamicType, "None");

// Enums

}