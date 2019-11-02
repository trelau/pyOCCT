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
#ifndef __Prs3d_Point__
#define __Prs3d_Point__

#include <Prs3d_Root.hxx>
#include <Prs3d_Point.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Group.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>

template <typename AnyPoint, typename PointTool>
void bind_Prs3d_Point(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<Prs3d_Point<AnyPoint, PointTool>> cls_Prs3d_Point(mod, name.c_str(), "None", local);

// Methods
// cls_Prs3d_Point.def_static("operator new_", (void * (*)(size_t)) &Prs3d_Point<AnyPoint, PointTool>::operator new, "None", py::arg("theSize"));
// cls_Prs3d_Point.def_static("operator delete_", (void (*)(void *)) &Prs3d_Point<AnyPoint, PointTool>::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d_Point.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d_Point<AnyPoint, PointTool>::operator new[], "None", py::arg("theSize"));
// cls_Prs3d_Point.def_static("operator delete[]_", (void (*)(void *)) &Prs3d_Point<AnyPoint, PointTool>::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d_Point.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d_Point<AnyPoint, PointTool>::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d_Point.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d_Point<AnyPoint, PointTool>::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d_Point.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const AnyPoint &, const opencascade::handle<Prs3d_Drawer> &)) &Prs3d_Point<AnyPoint, PointTool>::Add, "None", py::arg("thePresentation"), py::arg("thePoint"), py::arg("theDrawer"));
cls_Prs3d_Point.def_static("Match_", (Standard_Boolean (*)(const AnyPoint &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Prs3d_Point<AnyPoint, PointTool>::Match, "None", py::arg("thePoint"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"));

}

#endif