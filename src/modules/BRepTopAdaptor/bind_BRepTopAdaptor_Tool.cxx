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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <BRepTopAdaptor_Tool.hxx>

void bind_BRepTopAdaptor_Tool(py::module &mod){

py::class_<BRepTopAdaptor_Tool, std::unique_ptr<BRepTopAdaptor_Tool>> cls_BRepTopAdaptor_Tool(mod, "BRepTopAdaptor_Tool", "None");

// Constructors
cls_BRepTopAdaptor_Tool.def(py::init<>());
cls_BRepTopAdaptor_Tool.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Surface"), py::arg("Tol2d"));

// Fields

// Methods
// cls_BRepTopAdaptor_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepTopAdaptor_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete_", (void (*)(void *)) &BRepTopAdaptor_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepTopAdaptor_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepTopAdaptor_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTopAdaptor_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepTopAdaptor_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const TopoDS_Face &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("F"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("Surface"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def("GetTopolTool", (opencascade::handle<BRepTopAdaptor_TopolTool> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetTopolTool, "None");
cls_BRepTopAdaptor_Tool.def("SetTopolTool", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<BRepTopAdaptor_TopolTool> &)) &BRepTopAdaptor_Tool::SetTopolTool, "None", py::arg("TT"));
cls_BRepTopAdaptor_Tool.def("GetSurface", (opencascade::handle<Adaptor3d_HSurface> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetSurface, "None");
cls_BRepTopAdaptor_Tool.def("Destroy", (void (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::Destroy, "None");

// Enums

}