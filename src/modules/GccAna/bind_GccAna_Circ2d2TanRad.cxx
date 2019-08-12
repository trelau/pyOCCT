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
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Circ2d2TanRad.hxx>

void bind_GccAna_Circ2d2TanRad(py::module &mod){

py::class_<GccAna_Circ2d2TanRad, std::unique_ptr<GccAna_Circ2d2TanRad, Deleter<GccAna_Circ2d2TanRad>>> cls_GccAna_Circ2d2TanRad(mod, "GccAna_Circ2d2TanRad", "This class implements the algorithms used to create 2d circles tangent to 2 points/lines/circles and with a given radius. For each construction methods arguments are: - Two Qualified elements for tangency constraints. (for example EnclosedCirc if we want the solution inside the argument EnclosedCirc). - Two Reals. One (Radius) for the radius and the other (Tolerance) for the tolerance. Tolerance is only used for the limit cases. For example : We want to create a circle inside a circle C1 and inside a circle C2 with a radius Radius and a tolerance Tolerance. If we do not use Tolerance it is impossible to find a solution in the following case : C2 is inside C1 and there is no intersection point between the two circles. With Tolerance it gives a solution if the lowest distance between C1 and C2 is lower than or equal Tolerance.");

// Constructors
cls_GccAna_Circ2d2TanRad.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanRad.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanRad.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanRad.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanRad.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanRad.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GccAna_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t)) &GccAna_Circ2d2TanRad::operator new, "None", py::arg("theSize"));
// cls_GccAna_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *)) &GccAna_Circ2d2TanRad::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Circ2d2TanRad.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Circ2d2TanRad::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Circ2d2TanRad.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Circ2d2TanRad::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Circ2d2TanRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Circ2d2TanRad::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Circ2d2TanRad.def("IsDone", (Standard_Boolean (GccAna_Circ2d2TanRad::*)() const) &GccAna_Circ2d2TanRad::IsDone, "This method returns True if the algorithm succeeded. Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_GccAna_Circ2d2TanRad.def("NbSolutions", (Standard_Integer (GccAna_Circ2d2TanRad::*)() const) &GccAna_Circ2d2TanRad::NbSolutions, "This method returns the number of circles, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails. of solutions.");
cls_GccAna_Circ2d2TanRad.def("ThisSolution", (gp_Circ2d (GccAna_Circ2d2TanRad::*)(const Standard_Integer) const) &GccAna_Circ2d2TanRad::ThisSolution, "Returns the solution number Index. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. Raises OutOfRange exception if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_GccAna_Circ2d2TanRad.def("WhichQualifier", (void (GccAna_Circ2d2TanRad::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &GccAna_Circ2d2TanRad::WhichQualifier, "Returns the information about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_GccAna_Circ2d2TanRad.def("Tangency1", [](GccAna_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntSol on the first argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d2TanRad.def("Tangency2", [](GccAna_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntArg on the second argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d2TanRad.def("IsTheSame1", (Standard_Boolean (GccAna_Circ2d2TanRad::*)(const Standard_Integer) const) &GccAna_Circ2d2TanRad::IsTheSame1, "Returns True if the solution number Index is equal to the first argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_GccAna_Circ2d2TanRad.def("IsTheSame2", (Standard_Boolean (GccAna_Circ2d2TanRad::*)(const Standard_Integer) const) &GccAna_Circ2d2TanRad::IsTheSame2, "Returns True if the solution number Index is equal to the second argument. Raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));

// Enums

}