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
#include <Prs3d_Presentation.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ViewAffinity.hxx>
#include <Prs3d_PresentationShadow.hxx>
#include <Standard_Type.hxx>

void bind_Prs3d_PresentationShadow(py::module &mod){

py::class_<Prs3d_PresentationShadow, opencascade::handle<Prs3d_PresentationShadow>, Prs3d_Presentation> cls_Prs3d_PresentationShadow(mod, "Prs3d_PresentationShadow", "Defines a 'shadow' of existing presentation object with custom aspects.");

// Constructors
cls_Prs3d_PresentationShadow.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Prs3d_Presentation> &>(), py::arg("theViewer"), py::arg("thePrs"));

// Fields

// Methods
cls_Prs3d_PresentationShadow.def("ParentId", (Standard_Integer (Prs3d_PresentationShadow::*)() const) &Prs3d_PresentationShadow::ParentId, "Returns the id of the parent presentation");
cls_Prs3d_PresentationShadow.def("ParentAffinity", (const opencascade::handle<Graphic3d_ViewAffinity> & (Prs3d_PresentationShadow::*)() const) &Prs3d_PresentationShadow::ParentAffinity, "Returns view affinity of the parent presentation");
cls_Prs3d_PresentationShadow.def("CalculateBoundBox", (void (Prs3d_PresentationShadow::*)()) &Prs3d_PresentationShadow::CalculateBoundBox, "Do nothing - axis-aligned bounding box should be initialized from parent structure.");
cls_Prs3d_PresentationShadow.def_static("get_type_name_", (const char * (*)()) &Prs3d_PresentationShadow::get_type_name, "None");
cls_Prs3d_PresentationShadow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PresentationShadow::get_type_descriptor, "None");
cls_Prs3d_PresentationShadow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PresentationShadow::*)() const) &Prs3d_PresentationShadow::DynamicType, "None");

// Enums

}