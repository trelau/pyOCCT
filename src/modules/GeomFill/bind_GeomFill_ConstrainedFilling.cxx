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
#include <Standard_Handle.hxx>
#include <GeomFill_Boundary.hxx>
#include <GeomFill_BoundWithSurf.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomFill_CoonsAlgPatch.hxx>
#include <GeomFill_TgtField.hxx>
#include <GeomFill_CornerState.hxx>
#include <gp_Vec.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <GeomFill_ConstrainedFilling.hxx>

void bind_GeomFill_ConstrainedFilling(py::module &mod){

py::class_<GeomFill_ConstrainedFilling> cls_GeomFill_ConstrainedFilling(mod, "GeomFill_ConstrainedFilling", "An algorithm for constructing a BSpline surface filled from a series of boundaries which serve as path constraints and optionally, as tangency constraints. The algorithm accepts three or four curves as the boundaries of the target surface. The only FillingStyle used is Coons. A ConstrainedFilling object provides a framework for: - defining the boundaries of the surface - implementing the construction algorithm - consulting the result. Warning This surface filling algorithm is specifically designed to be used in connection with fillets. Satisfactory results cannot be guaranteed for other uses.");

// Constructors
cls_GeomFill_ConstrainedFilling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("MaxDeg"), py::arg("MaxSeg"));

// Fields

// Methods
// cls_GeomFill_ConstrainedFilling.def_static("operator new_", (void * (*)(size_t)) &GeomFill_ConstrainedFilling::operator new, "None", py::arg("theSize"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete_", (void (*)(void *)) &GeomFill_ConstrainedFilling::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_ConstrainedFilling::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_ConstrainedFilling::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_ConstrainedFilling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_ConstrainedFilling::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_ConstrainedFilling.def("Init", [](GeomFill_ConstrainedFilling &self, const opencascade::handle<GeomFill_Boundary> & a0, const opencascade::handle<GeomFill_Boundary> & a1, const opencascade::handle<GeomFill_Boundary> & a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomFill_ConstrainedFilling.def("Init", (void (GeomFill_ConstrainedFilling::*)(const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const Standard_Boolean)) &GeomFill_ConstrainedFilling::Init, "None", py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("NoCheck"));
cls_GeomFill_ConstrainedFilling.def("Init", [](GeomFill_ConstrainedFilling &self, const opencascade::handle<GeomFill_Boundary> & a0, const opencascade::handle<GeomFill_Boundary> & a1, const opencascade::handle<GeomFill_Boundary> & a2, const opencascade::handle<GeomFill_Boundary> & a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomFill_ConstrainedFilling.def("Init", (void (GeomFill_ConstrainedFilling::*)(const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const Standard_Boolean)) &GeomFill_ConstrainedFilling::Init, "Constructs a BSpline surface filled from the series of boundaries B1, B2, B3 and, if need be, B4, which serve: - as path constraints - and optionally, as tangency constraints if they are GeomFill_BoundWithSurf curves. The boundaries may be given in any order: they are classified and if necessary, reversed and reparameterized. The surface will also respect the following constraints: - its degree will not be greater than the maximum degree defined at the time of construction of this framework, and - the maximum number of segments MaxSeg which BSpline surfaces can have", py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("B4"), py::arg("NoCheck"));
cls_GeomFill_ConstrainedFilling.def("SetDomain", (void (GeomFill_ConstrainedFilling::*)(const Standard_Real, const opencascade::handle<GeomFill_BoundWithSurf> &)) &GeomFill_ConstrainedFilling::SetDomain, "Allows to modify domain on witch the blending function associated to the constrained boundary B will propag the influence of the field of tangency. Can be usefull to reduce influence of boundaries on whitch the Coons compatibility conditions are not respected. l is a relative value of the parametric range of B. Default value for l is 1 (used in Init). Warning: Must be called after Init with a constrained boundary used in the call to Init.", py::arg("l"), py::arg("B"));
cls_GeomFill_ConstrainedFilling.def("ReBuild", (void (GeomFill_ConstrainedFilling::*)()) &GeomFill_ConstrainedFilling::ReBuild, "Computes the new poles of the surface using the new blending functions set by several calls to SetDomain.");
cls_GeomFill_ConstrainedFilling.def("Boundary", (opencascade::handle<GeomFill_Boundary> (GeomFill_ConstrainedFilling::*)(const Standard_Integer) const) &GeomFill_ConstrainedFilling::Boundary, "Returns the bound of index i after sort.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_ConstrainedFilling::*)() const) &GeomFill_ConstrainedFilling::Surface, "Returns the BSpline surface after computation of the fill by this framework.");
cls_GeomFill_ConstrainedFilling.def("Eval", [](GeomFill_ConstrainedFilling &self, const Standard_Real W, const Standard_Integer Ord, Standard_Real & Result){ Standard_Integer rv = self.Eval(W, Ord, Result); return std::tuple<Standard_Integer, Standard_Real &>(rv, Result); }, "Internal use for Advmath approximation call.", py::arg("W"), py::arg("Ord"), py::arg("Result"));
cls_GeomFill_ConstrainedFilling.def("CheckCoonsAlgPatch", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckCoonsAlgPatch, "Computes the fields of tangents on 30 points along the bound I, these are not the constraint tangents but gives an idea of the coonsAlgPatch regularity.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckTgteField", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckTgteField, "Computes the fields of tangents and normals on 30 points along the bound I, draw them, and computes the max dot product that must be near than 0.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckApprox", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckApprox, "Computes values and normals along the bound I and compare them to the approx result curves (bound and tgte field) , draw the normals and tangents.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckResult", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckResult, "Computes values and normals along the bound I on both constraint surface and result surface, draw the normals, and computes the max distance between values and the max angle between normals.", py::arg("I"));

// Enums

}