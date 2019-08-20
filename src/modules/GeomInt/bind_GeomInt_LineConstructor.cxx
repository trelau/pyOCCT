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
#include <Adaptor3d_TopolTool.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <IntPatch_Line.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GeomInt_LineConstructor.hxx>

void bind_GeomInt_LineConstructor(py::module &mod){

py::class_<GeomInt_LineConstructor, std::unique_ptr<GeomInt_LineConstructor>> cls_GeomInt_LineConstructor(mod, "GeomInt_LineConstructor", "Splits given Line.");

// Constructors
cls_GeomInt_LineConstructor.def(py::init<>());

// Fields

// Methods
// cls_GeomInt_LineConstructor.def_static("operator new_", (void * (*)(size_t)) &GeomInt_LineConstructor::operator new, "None", py::arg("theSize"));
// cls_GeomInt_LineConstructor.def_static("operator delete_", (void (*)(void *)) &GeomInt_LineConstructor::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_LineConstructor.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_LineConstructor::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_LineConstructor.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_LineConstructor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_LineConstructor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_LineConstructor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_LineConstructor.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_LineConstructor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_LineConstructor.def("Load", (void (GeomInt_LineConstructor::*)(const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &)) &GeomInt_LineConstructor::Load, "Initializes me by two surfaces and corresponding tools which represent boundaries of surfaces", py::arg("D1"), py::arg("D2"), py::arg("S1"), py::arg("S2"));
cls_GeomInt_LineConstructor.def("Perform", (void (GeomInt_LineConstructor::*)(const opencascade::handle<IntPatch_Line> &)) &GeomInt_LineConstructor::Perform, "Splits line", py::arg("L"));
cls_GeomInt_LineConstructor.def("IsDone", (Standard_Boolean (GeomInt_LineConstructor::*)() const) &GeomInt_LineConstructor::IsDone, "Returns True if splitting was successful");
cls_GeomInt_LineConstructor.def("NbParts", (Standard_Integer (GeomInt_LineConstructor::*)() const) &GeomInt_LineConstructor::NbParts, "Returns number of splits");
cls_GeomInt_LineConstructor.def("Part", [](GeomInt_LineConstructor &self, const Standard_Integer I, Standard_Real & WFirst, Standard_Real & WLast){ self.Part(I, WFirst, WLast); return std::tuple<Standard_Real &, Standard_Real &>(WFirst, WLast); }, "Return first and last parameters for given index of split", py::arg("I"), py::arg("WFirst"), py::arg("WLast"));

// Enums

}