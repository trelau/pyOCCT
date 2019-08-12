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
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <HLRBRep_TheQuadCurvExactInterCSurf.hxx>

void bind_HLRBRep_TheQuadCurvExactInterCSurf(py::module &mod){

py::class_<HLRBRep_TheQuadCurvExactInterCSurf, std::unique_ptr<HLRBRep_TheQuadCurvExactInterCSurf, Deleter<HLRBRep_TheQuadCurvExactInterCSurf>>> cls_HLRBRep_TheQuadCurvExactInterCSurf(mod, "HLRBRep_TheQuadCurvExactInterCSurf", "None");

// Constructors
cls_HLRBRep_TheQuadCurvExactInterCSurf.def(py::init<const Standard_Address &, const gp_Lin &>(), py::arg("S"), py::arg("C"));

// Fields

// Methods
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("IsDone", (Standard_Boolean (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::IsDone, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("NbRoots", (Standard_Integer (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::NbRoots, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("Root", (Standard_Real (HLRBRep_TheQuadCurvExactInterCSurf::*)(const Standard_Integer) const) &HLRBRep_TheQuadCurvExactInterCSurf::Root, "None", py::arg("Index"));
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("NbIntervals", (Standard_Integer (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::NbIntervals, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("Intervals", [](HLRBRep_TheQuadCurvExactInterCSurf &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Intervals(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "U1 and U2 are the parameters of a segment on the curve.", py::arg("Index"), py::arg("U1"), py::arg("U2"));

// Enums

}