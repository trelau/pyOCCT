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
#include <IntPatch_Line.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_RstInt.hxx>

void bind_IntPatch_RstInt(py::module &mod){

py::class_<IntPatch_RstInt, std::unique_ptr<IntPatch_RstInt>> cls_IntPatch_RstInt(mod, "IntPatch_RstInt", "trouver les points d intersection entre la ligne de cheminement et les arcs de restriction");

// Constructors

// Fields

// Methods
// cls_IntPatch_RstInt.def_static("operator new_", (void * (*)(size_t)) &IntPatch_RstInt::operator new, "None", py::arg("theSize"));
// cls_IntPatch_RstInt.def_static("operator delete_", (void (*)(void *)) &IntPatch_RstInt::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_RstInt.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_RstInt::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_RstInt.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_RstInt::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_RstInt.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_RstInt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_RstInt.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_RstInt::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_RstInt.def_static("PutVertexOnLine_", (void (*)(const opencascade::handle<IntPatch_Line> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean, const Standard_Real)) &IntPatch_RstInt::PutVertexOnLine, "None", py::arg("L"), py::arg("Surf"), py::arg("Domain"), py::arg("OtherSurf"), py::arg("OnFirst"), py::arg("Tol"));

// Enums

}