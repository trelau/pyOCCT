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
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <IntCurveSurface_TheQuadCurvExactHInter.hxx>

void bind_IntCurveSurface_TheQuadCurvExactHInter(py::module &mod){

py::class_<IntCurveSurface_TheQuadCurvExactHInter, std::unique_ptr<IntCurveSurface_TheQuadCurvExactHInter>> cls_IntCurveSurface_TheQuadCurvExactHInter(mod, "IntCurveSurface_TheQuadCurvExactHInter", "None");

// Constructors
cls_IntCurveSurface_TheQuadCurvExactHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Fields

// Methods
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvExactHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvExactHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheQuadCurvExactHInter.def("IsDone", (Standard_Boolean (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::IsDone, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("NbRoots", (Standard_Integer (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::NbRoots, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("Root", (Standard_Real (IntCurveSurface_TheQuadCurvExactHInter::*)(const Standard_Integer) const) &IntCurveSurface_TheQuadCurvExactHInter::Root, "None", py::arg("Index"));
cls_IntCurveSurface_TheQuadCurvExactHInter.def("NbIntervals", (Standard_Integer (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::NbIntervals, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("Intervals", [](IntCurveSurface_TheQuadCurvExactHInter &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Intervals(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "U1 and U2 are the parameters of a segment on the curve.", py::arg("Index"), py::arg("U1"), py::arg("U2"));

// Enums

}