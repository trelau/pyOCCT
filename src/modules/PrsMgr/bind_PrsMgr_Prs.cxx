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
#include <PrsMgr_Presentation.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <PrsMgr_PresentationPointer.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <PrsMgr_Prs.hxx>
#include <Standard_Type.hxx>

void bind_PrsMgr_Prs(py::module &mod){

py::class_<PrsMgr_Prs, opencascade::handle<PrsMgr_Prs>, Prs3d_Presentation> cls_PrsMgr_Prs(mod, "PrsMgr_Prs", "None");

// Constructors
cls_PrsMgr_Prs.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const PrsMgr_PresentationPointer &, const PrsMgr_TypeOfPresentation3d>(), py::arg("theStructManager"), py::arg("thePresentation"), py::arg("theTypeOfPresentation3d"));

// Fields

// Methods
cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)()) &PrsMgr_Prs::Compute, "None");
cls_PrsMgr_Prs.def("Compute", (opencascade::handle<Graphic3d_Structure> (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &PrsMgr_Prs::Compute, "None", py::arg("aProjector"));
cls_PrsMgr_Prs.def("Compute", (opencascade::handle<Graphic3d_Structure> (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &PrsMgr_Prs::Compute, "the 'degenerated' Structure is displayed with a transformation defined by <AMatrix> which is not a Pure Translation. We have to take in account this Transformation in the computation of hidden line removal... returns a filled Graphic Structure.", py::arg("theProjector"), py::arg("theTrsf"));
cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &PrsMgr_Prs::Compute, "No need to return a structure, just to fill <ComputedStruct> ....", py::arg("aProjector"), py::arg("ComputedStruct"));
cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &PrsMgr_Prs::Compute, "No Need to return a Structure, just to Fill <aStructure>. The Trsf has to be taken in account in the computation (Rotation Part....)", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
cls_PrsMgr_Prs.def_static("get_type_name_", (const char * (*)()) &PrsMgr_Prs::get_type_name, "None");
cls_PrsMgr_Prs.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_Prs::get_type_descriptor, "None");
cls_PrsMgr_Prs.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_Prs::*)() const) &PrsMgr_Prs::DynamicType, "None");

// Enums

}