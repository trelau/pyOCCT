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
#include <gp_Circ2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Lin2dTanPer.hxx>

void bind_GccAna_Lin2dTanPer(py::module &mod){

py::class_<GccAna_Lin2dTanPer> cls_GccAna_Lin2dTanPer(mod, "GccAna_Lin2dTanPer", "This class implements the algorithms used to create 2d lines tangent to a circle or a point and perpendicular to a line or a circle. Describes functions for building a 2D line perpendicular to a line and: - tangential to a circle, or - passing through a point. A Lin2dTanPer object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_GccAna_Lin2dTanPer.def(py::init<const gp_Pnt2d &, const gp_Lin2d &>(), py::arg("ThePnt"), py::arg("TheLin"));
cls_GccAna_Lin2dTanPer.def(py::init<const gp_Pnt2d &, const gp_Circ2d &>(), py::arg("ThePnt"), py::arg("TheCircle"));
cls_GccAna_Lin2dTanPer.def(py::init<const GccEnt_QualifiedCirc &, const gp_Lin2d &>(), py::arg("Qualified1"), py::arg("TheLin"));
cls_GccAna_Lin2dTanPer.def(py::init<const GccEnt_QualifiedCirc &, const gp_Circ2d &>(), py::arg("Qualified1"), py::arg("TheCircle"));

// Fields

// Methods
// cls_GccAna_Lin2dTanPer.def_static("operator new_", (void * (*)(size_t)) &GccAna_Lin2dTanPer::operator new, "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanPer.def_static("operator delete_", (void (*)(void *)) &GccAna_Lin2dTanPer::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanPer.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Lin2dTanPer::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanPer.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Lin2dTanPer::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanPer.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Lin2dTanPer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Lin2dTanPer.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Lin2dTanPer::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Lin2dTanPer.def("IsDone", (Standard_Boolean (GccAna_Lin2dTanPer::*)() const) &GccAna_Lin2dTanPer::IsDone, "Returns True if the algorithm succeeded.");
cls_GccAna_Lin2dTanPer.def("NbSolutions", (Standard_Integer (GccAna_Lin2dTanPer::*)() const) &GccAna_Lin2dTanPer::NbSolutions, "Returns the number of solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Lin2dTanPer.def("WhichQualifier", (void (GccAna_Lin2dTanPer::*)(const Standard_Integer, GccEnt_Position &) const) &GccAna_Lin2dTanPer::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the argument, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_GccAna_Lin2dTanPer.def("ThisSolution", (gp_Lin2d (GccAna_Lin2dTanPer::*)(const Standard_Integer) const) &GccAna_Lin2dTanPer::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_GccAna_Lin2dTanPer.def("Tangency1", [](GccAna_Lin2dTanPer &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & Pnt){ self.Tangency1(Index, ParSol, ParArg, Pnt); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. If the first argument is a point ParArg is equal zero. raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("Pnt"));
cls_GccAna_Lin2dTanPer.def("Intersection2", [](GccAna_Lin2dTanPer &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the intersection between the solution number Index and the second argument. It returns the first intersection in a case of Lin2dTanPer which is perpendicular to a circle . ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}