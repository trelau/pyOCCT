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
#include <gp_Pnt2d.hxx>
#include <HLRBRep_TheProjPCurOfCInter.hxx>

void bind_HLRBRep_TheProjPCurOfCInter(py::module &mod){

py::class_<HLRBRep_TheProjPCurOfCInter, std::unique_ptr<HLRBRep_TheProjPCurOfCInter, Deleter<HLRBRep_TheProjPCurOfCInter>>> cls_HLRBRep_TheProjPCurOfCInter(mod, "HLRBRep_TheProjPCurOfCInter", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheProjPCurOfCInter.def_static("FindParameter_", (Standard_Real (*)(const Standard_Address &, const gp_Pnt2d &, const Standard_Real)) &HLRBRep_TheProjPCurOfCInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. In that case, no bounds are given. The research of the rigth parameter has to be made on the natural parametric domain of the curve.", py::arg("C"), py::arg("Pnt"), py::arg("Tol"));
cls_HLRBRep_TheProjPCurOfCInter.def_static("FindParameter_", (Standard_Real (*)(const Standard_Address &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheProjPCurOfCInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. LowParameter and HighParameter give the boundaries of the interval in wich the parameter certainly lies. These parameters are given to implement a more efficient algoritm. So, it is not necessary to check that the returned value verifies LowParameter <= Value <= HighParameter.", py::arg("C"), py::arg("Pnt"), py::arg("LowParameter"), py::arg("HighParameter"), py::arg("Tol"));

// Enums

}