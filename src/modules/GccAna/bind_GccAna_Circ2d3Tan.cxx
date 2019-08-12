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
#include <GccEnt_QualifiedCirc.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Circ2d3Tan.hxx>

void bind_GccAna_Circ2d3Tan(py::module &mod){

py::class_<GccAna_Circ2d3Tan, std::unique_ptr<GccAna_Circ2d3Tan, Deleter<GccAna_Circ2d3Tan>>> cls_GccAna_Circ2d3Tan(mod, "GccAna_Circ2d3Tan", "This class implements the algorithms used to create 2d circles tangent to 3 points/lines/circles. The arguments of all construction methods are : - The three qualified elements for the tangency constraints (QualifiedCirc, QualifiedLine, Points). - A real Tolerance. Tolerance is only used in the limit cases. For example : We want to create a circle tangent to an UnqualifiedCirc C1 and an UnqualifiedCirc C2 and an UnqualifiedCirc C3 with a tolerance Tolerance. If we do not use Tolerance it is impossible to find a solution in the following case : C2 is inside C1 and there is no intersection point between the two circles, and C3 is completly outside C1. With Tolerance we will find a solution if the lowest distance between C1 and C2 is lower than or equal Tolerance.");

// Constructors
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tolerance"));
cls_GccAna_Circ2d3Tan.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GccAna_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t)) &GccAna_Circ2d3Tan::operator new, "None", py::arg("theSize"));
// cls_GccAna_Circ2d3Tan.def_static("operator delete_", (void (*)(void *)) &GccAna_Circ2d3Tan::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Circ2d3Tan.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Circ2d3Tan::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Circ2d3Tan.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Circ2d3Tan::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Circ2d3Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Circ2d3Tan.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Circ2d3Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Circ2d3Tan.def("IsDone", (Standard_Boolean (GccAna_Circ2d3Tan::*)() const) &GccAna_Circ2d3Tan::IsDone, "This method returns True if the construction algorithm succeeded. Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_GccAna_Circ2d3Tan.def("NbSolutions", (Standard_Integer (GccAna_Circ2d3Tan::*)() const) &GccAna_Circ2d3Tan::NbSolutions, "This method returns the number of solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Circ2d3Tan.def("ThisSolution", (gp_Circ2d (GccAna_Circ2d3Tan::*)(const Standard_Integer) const) &GccAna_Circ2d3Tan::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"));
cls_GccAna_Circ2d3Tan.def("WhichQualifier", (void (GccAna_Circ2d3Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &, GccEnt_Position &) const) &GccAna_Circ2d3Tan::WhichQualifier, "Returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"), py::arg("Qualif3"));
cls_GccAna_Circ2d3Tan.def("Tangency1", [](GccAna_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntArg on the argument curv. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d3Tan.def("Tangency2", [](GccAna_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point Pntsol on the argument curv. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d3Tan.def("Tangency3", [](GccAna_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency3(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point Pntsol on the argument curv. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d3Tan.def("IsTheSame1", (Standard_Boolean (GccAna_Circ2d3Tan::*)(const Standard_Integer) const) &GccAna_Circ2d3Tan::IsTheSame1, "Returns True if the solution number Index is equal to the first argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"));
cls_GccAna_Circ2d3Tan.def("IsTheSame2", (Standard_Boolean (GccAna_Circ2d3Tan::*)(const Standard_Integer) const) &GccAna_Circ2d3Tan::IsTheSame2, "Returns True if the solution number Index is equal to the second argument. Raises OutOfRange Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"));
cls_GccAna_Circ2d3Tan.def("IsTheSame3", (Standard_Boolean (GccAna_Circ2d3Tan::*)(const Standard_Integer) const) &GccAna_Circ2d3Tan::IsTheSame3, "Returns True if the solution number Index is equal to the third argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"));

// Enums

}