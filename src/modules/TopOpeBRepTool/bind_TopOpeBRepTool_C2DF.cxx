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
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepTool_C2DF.hxx>

void bind_TopOpeBRepTool_C2DF(py::module &mod){

py::class_<TopOpeBRepTool_C2DF, std::unique_ptr<TopOpeBRepTool_C2DF, Deleter<TopOpeBRepTool_C2DF>>> cls_TopOpeBRepTool_C2DF(mod, "TopOpeBRepTool_C2DF", "None");

// Constructors
cls_TopOpeBRepTool_C2DF.def(py::init<>());
cls_TopOpeBRepTool_C2DF.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &>(), py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"), py::arg("F"));

// Fields

// Methods
// cls_TopOpeBRepTool_C2DF.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_C2DF::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_C2DF::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_C2DF::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_C2DF::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_C2DF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_C2DF::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_C2DF.def("SetPC", (void (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_C2DF::SetPC, "None", py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
cls_TopOpeBRepTool_C2DF.def("SetFace", (void (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &)) &TopOpeBRepTool_C2DF::SetFace, "None", py::arg("F"));
cls_TopOpeBRepTool_C2DF.def("PC", [](TopOpeBRepTool_C2DF &self, Standard_Real & f2d, Standard_Real & l2d, Standard_Real & tol){ const opencascade::handle<Geom2d_Curve> & rv = self.PC(f2d, l2d, tol); return std::tuple<const opencascade::handle<Geom2d_Curve> &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, f2d, l2d, tol); }, "None", py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
cls_TopOpeBRepTool_C2DF.def("Face", (const TopoDS_Face & (TopOpeBRepTool_C2DF::*)() const) &TopOpeBRepTool_C2DF::Face, "None");
cls_TopOpeBRepTool_C2DF.def("IsPC", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepTool_C2DF::IsPC, "None", py::arg("PC"));
cls_TopOpeBRepTool_C2DF.def("IsFace", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &) const) &TopOpeBRepTool_C2DF::IsFace, "None", py::arg("F"));

// Enums

}