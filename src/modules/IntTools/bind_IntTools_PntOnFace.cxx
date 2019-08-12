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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_PntOnFace.hxx>

void bind_IntTools_PntOnFace(py::module &mod){

py::class_<IntTools_PntOnFace, std::unique_ptr<IntTools_PntOnFace, Deleter<IntTools_PntOnFace>>> cls_IntTools_PntOnFace(mod, "IntTools_PntOnFace", "Contains a Face, a 3d point, corresponded UV parameters and a flag");

// Constructors
cls_IntTools_PntOnFace.def(py::init<>());

// Fields

// Methods
// cls_IntTools_PntOnFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_PntOnFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_PntOnFace.def_static("operator delete_", (void (*)(void *)) &IntTools_PntOnFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_PntOnFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_PntOnFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_PntOnFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_PntOnFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_PntOnFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_PntOnFace.def("Init", (void (IntTools_PntOnFace::*)(const TopoDS_Face &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::Init, "Initializes me by aFace, a 3d point and it's UV parameters on face", py::arg("aF"), py::arg("aP"), py::arg("U"), py::arg("V"));
cls_IntTools_PntOnFace.def("SetFace", (void (IntTools_PntOnFace::*)(const TopoDS_Face &)) &IntTools_PntOnFace::SetFace, "Modifier", py::arg("aF"));
cls_IntTools_PntOnFace.def("SetPnt", (void (IntTools_PntOnFace::*)(const gp_Pnt &)) &IntTools_PntOnFace::SetPnt, "Modifier", py::arg("aP"));
cls_IntTools_PntOnFace.def("SetParameters", (void (IntTools_PntOnFace::*)(const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::SetParameters, "Modifier", py::arg("U"), py::arg("V"));
cls_IntTools_PntOnFace.def("SetValid", (void (IntTools_PntOnFace::*)(const Standard_Boolean)) &IntTools_PntOnFace::SetValid, "Modifier", py::arg("bF"));
cls_IntTools_PntOnFace.def("Valid", (Standard_Boolean (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Valid, "Selector");
cls_IntTools_PntOnFace.def("Face", (const TopoDS_Face & (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Face, "Selector");
cls_IntTools_PntOnFace.def("Pnt", (const gp_Pnt & (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Pnt, "Selector");
cls_IntTools_PntOnFace.def("Parameters", [](IntTools_PntOnFace &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Selector", py::arg("U"), py::arg("V"));
// cls_IntTools_PntOnFace.def("IsValid", (Standard_Boolean (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::IsValid, "Selector");

// Enums

}