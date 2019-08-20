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
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Lin2dBisec.hxx>

void bind_GccAna_Lin2dBisec(py::module &mod){

py::class_<GccAna_Lin2dBisec, std::unique_ptr<GccAna_Lin2dBisec>> cls_GccAna_Lin2dBisec(mod, "GccAna_Lin2dBisec", "Describes functions for building bisecting lines between two 2D lines. A bisecting line between two lines is such that each of its points is at the same distance from the two lines. If the two lines are secant, there are two orthogonal bisecting lines which share the angles made by the two straight lines in two equal parts. If D1 and D2 are the unit vectors of the two straight lines, those of the two bisecting lines are collinear with the following vectors: - D1 + D2 for the 'internal' bisecting line, - D1 - D2 for the 'external' bisecting line. If the two lines are parallel, the (unique) bisecting line is the straight line equidistant from the two straight lines. If the two straight lines are coincident, the algorithm returns the first straight line as the solution. A Lin2dTanObl object provides a framework for: - defining the construction of the bisecting lines, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GccAna_Lin2dBisec.def(py::init<const gp_Lin2d &, const gp_Lin2d &>(), py::arg("Lin1"), py::arg("Lin2"));

// Fields

// Methods
// cls_GccAna_Lin2dBisec.def_static("operator new_", (void * (*)(size_t)) &GccAna_Lin2dBisec::operator new, "None", py::arg("theSize"));
// cls_GccAna_Lin2dBisec.def_static("operator delete_", (void (*)(void *)) &GccAna_Lin2dBisec::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Lin2dBisec.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Lin2dBisec::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Lin2dBisec.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Lin2dBisec::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Lin2dBisec.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Lin2dBisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Lin2dBisec.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Lin2dBisec::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Lin2dBisec.def("IsDone", (Standard_Boolean (GccAna_Lin2dBisec::*)() const) &GccAna_Lin2dBisec::IsDone, "Returns True when the algorithm succeded.");
cls_GccAna_Lin2dBisec.def("NbSolutions", (Standard_Integer (GccAna_Lin2dBisec::*)() const) &GccAna_Lin2dBisec::NbSolutions, "Returns the number of solutions and raise NotDone if the constructor wasn't called before.");
cls_GccAna_Lin2dBisec.def("ThisSolution", (gp_Lin2d (GccAna_Lin2dBisec::*)(const Standard_Integer) const) &GccAna_Lin2dBisec::ThisSolution, "Returns the solution number Index . The first solution is the inside one and the second is the outside one. For the first solution the direction is D1+D2 (D1 is the direction of the first argument and D2 the direction of the second argument). For the second solution the direction is D1-D2. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_GccAna_Lin2dBisec.def("Intersection1", [](GccAna_Lin2dBisec &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the intersection point between the result number Index and the first argument. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Lin2dBisec.def("Intersection2", [](GccAna_Lin2dBisec &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the intersection point between the result number Index and the second argument. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}