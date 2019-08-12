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
#include <Geom2dInt_GInter.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Dir2d.hxx>
#include <Geom2dHatch_Intersector.hxx>

void bind_Geom2dHatch_Intersector(py::module &mod){

py::class_<Geom2dHatch_Intersector, std::unique_ptr<Geom2dHatch_Intersector, Deleter<Geom2dHatch_Intersector>>, Geom2dInt_GInter> cls_Geom2dHatch_Intersector(mod, "Geom2dHatch_Intersector", "None");

// Constructors
cls_Geom2dHatch_Intersector.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Confusion"), py::arg("Tangency"));
cls_Geom2dHatch_Intersector.def(py::init<>());

// Fields

// Methods
// cls_Geom2dHatch_Intersector.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Intersector::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Intersector.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Intersector::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Intersector.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Intersector.def("ConfusionTolerance", (Standard_Real (Geom2dHatch_Intersector::*)() const) &Geom2dHatch_Intersector::ConfusionTolerance, "Returns the confusion tolerance of the intersector.");
cls_Geom2dHatch_Intersector.def("SetConfusionTolerance", (void (Geom2dHatch_Intersector::*)(const Standard_Real)) &Geom2dHatch_Intersector::SetConfusionTolerance, "Sets the confusion tolerance of the intersector.", py::arg("Confusion"));
cls_Geom2dHatch_Intersector.def("TangencyTolerance", (Standard_Real (Geom2dHatch_Intersector::*)() const) &Geom2dHatch_Intersector::TangencyTolerance, "Returns the tangency tolerance of the intersector.");
cls_Geom2dHatch_Intersector.def("SetTangencyTolerance", (void (Geom2dHatch_Intersector::*)(const Standard_Real)) &Geom2dHatch_Intersector::SetTangencyTolerance, "Sets the tangency tolerance of the intersector.", py::arg("Tangency"));
cls_Geom2dHatch_Intersector.def("Intersect", (void (Geom2dHatch_Intersector::*)(const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &)) &Geom2dHatch_Intersector::Intersect, "Intersects the curves C1 and C2. The results are retreived by the usual methods described in IntRes2d_Intersection. Creates an intersector.", py::arg("C1"), py::arg("C2"));
cls_Geom2dHatch_Intersector.def("Perform", (void (Geom2dHatch_Intersector::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const Geom2dAdaptor_Curve &)) &Geom2dHatch_Intersector::Perform, "Performs the intersection between the 2d line segment (<L>, <P>) and the Curve <E>. The line segment is the part of the 2d line <L> of parameter range [0, <P>] (P is positive and can be RealLast()). Tol is the Tolerance on the segment. The order is relevant, the first argument is the segment, the second the Edge.", py::arg("L"), py::arg("P"), py::arg("Tol"), py::arg("E"));
cls_Geom2dHatch_Intersector.def("LocalGeometry", [](Geom2dHatch_Intersector &self, const Geom2dAdaptor_Curve & E, const Standard_Real U, gp_Dir2d & T, gp_Dir2d & N, Standard_Real & C){ self.LocalGeometry(E, U, T, N, C); return C; }, "Returns in <T>, <N> and <C> the tangent, normal and curvature of the edge <E> at parameter value <U>.", py::arg("E"), py::arg("U"), py::arg("T"), py::arg("N"), py::arg("C"));

// Enums

}