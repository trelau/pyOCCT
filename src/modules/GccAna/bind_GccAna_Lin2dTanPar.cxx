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
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Lin2dTanPar.hxx>

void bind_GccAna_Lin2dTanPar(py::module &mod){

py::class_<GccAna_Lin2dTanPar> cls_GccAna_Lin2dTanPar(mod, "GccAna_Lin2dTanPar", "This class implements the algorithms used to create 2d line tangent to a circle or a point and parallel to another line. The solution has the same orientation as the second argument. Describes functions for building a 2D line parallel to a line and: - tangential to a circle, or - passing through a point. A Lin2dTanPar object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and consulting the result(s).");

// Constructors
cls_GccAna_Lin2dTanPar.def(py::init<const gp_Pnt2d &, const gp_Lin2d &>(), py::arg("ThePoint"), py::arg("Lin1"));
cls_GccAna_Lin2dTanPar.def(py::init<const GccEnt_QualifiedCirc &, const gp_Lin2d &>(), py::arg("Qualified1"), py::arg("Lin1"));

// Fields

// Methods
// cls_GccAna_Lin2dTanPar.def_static("operator new_", (void * (*)(size_t)) &GccAna_Lin2dTanPar::operator new, "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanPar.def_static("operator delete_", (void (*)(void *)) &GccAna_Lin2dTanPar::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanPar.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Lin2dTanPar::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanPar.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Lin2dTanPar::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanPar.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Lin2dTanPar::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Lin2dTanPar.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Lin2dTanPar::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Lin2dTanPar.def("IsDone", (Standard_Boolean (GccAna_Lin2dTanPar::*)() const) &GccAna_Lin2dTanPar::IsDone, "Returns True if the algorithm succeeded.");
cls_GccAna_Lin2dTanPar.def("NbSolutions", (Standard_Integer (GccAna_Lin2dTanPar::*)() const) &GccAna_Lin2dTanPar::NbSolutions, "Returns the number of solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Lin2dTanPar.def("ThisSolution", (gp_Lin2d (GccAna_Lin2dTanPar::*)(const Standard_Integer) const) &GccAna_Lin2dTanPar::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_GccAna_Lin2dTanPar.def("WhichQualifier", (void (GccAna_Lin2dTanPar::*)(const Standard_Integer, GccEnt_Position &) const) &GccAna_Lin2dTanPar::WhichQualifier, "Returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computed in case of unqualified). Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("Qualif1"));
cls_GccAna_Lin2dTanPar.def("Tangency1", [](GccAna_Lin2dTanPar &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & Pnt){ self.Tangency1(Index, ParSol, ParArg, Pnt); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. ParArg is equal 0 when the solution is passing thrue a point. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("Pnt"));

// Enums

}