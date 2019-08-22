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
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_ShrunkRange.hxx>

void bind_IntTools_ShrunkRange(py::module &mod){

py::class_<IntTools_ShrunkRange> cls_IntTools_ShrunkRange(mod, "IntTools_ShrunkRange", "The class provides the computation of a working (shrunk) range [t1, t2] for the 3D-curve of the edge.");

// Constructors
cls_IntTools_ShrunkRange.def(py::init<>());

// Fields

// Methods
// cls_IntTools_ShrunkRange.def_static("operator new_", (void * (*)(size_t)) &IntTools_ShrunkRange::operator new, "None", py::arg("theSize"));
// cls_IntTools_ShrunkRange.def_static("operator delete_", (void (*)(void *)) &IntTools_ShrunkRange::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_ShrunkRange::operator new[], "None", py::arg("theSize"));
// cls_IntTools_ShrunkRange.def_static("operator delete[]_", (void (*)(void *)) &IntTools_ShrunkRange::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_ShrunkRange::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_ShrunkRange::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_ShrunkRange.def("SetData", (void (IntTools_ShrunkRange::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Vertex &)) &IntTools_ShrunkRange::SetData, "None", py::arg("aE"), py::arg("aT1"), py::arg("aT2"), py::arg("aV1"), py::arg("aV2"));
cls_IntTools_ShrunkRange.def("SetContext", (void (IntTools_ShrunkRange::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_ShrunkRange::SetContext, "None", py::arg("aCtx"));
cls_IntTools_ShrunkRange.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::Context, "None");
cls_IntTools_ShrunkRange.def("SetShrunkRange", (void (IntTools_ShrunkRange::*)(const Standard_Real, const Standard_Real)) &IntTools_ShrunkRange::SetShrunkRange, "None", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_ShrunkRange.def("ShrunkRange", [](IntTools_ShrunkRange &self, Standard_Real & aT1, Standard_Real & aT2){ self.ShrunkRange(aT1, aT2); return std::tuple<Standard_Real &, Standard_Real &>(aT1, aT2); }, "None", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_ShrunkRange.def("BndBox", (const Bnd_Box & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::BndBox, "None");
cls_IntTools_ShrunkRange.def("Edge", (const TopoDS_Edge & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::Edge, "None");
cls_IntTools_ShrunkRange.def("Perform", (void (IntTools_ShrunkRange::*)()) &IntTools_ShrunkRange::Perform, "None");
cls_IntTools_ShrunkRange.def("IsDone", (Standard_Boolean (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::IsDone, "Returns TRUE in case the shrunk range is computed");
cls_IntTools_ShrunkRange.def("IsSplittable", (Standard_Boolean (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::IsSplittable, "Returns FALSE in case the shrunk range is too short and the edge cannot be split, otherwise returns TRUE");

// Enums

}