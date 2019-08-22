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
#include <Geom2dGcc_QualifiedCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Point.hxx>
#include <GccAna_Circ2d2TanRad.hxx>
#include <Geom2dGcc_Circ2d2TanRadGeo.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2d2TanRad.hxx>

void bind_Geom2dGcc_Circ2d2TanRad(py::module &mod){

py::class_<Geom2dGcc_Circ2d2TanRad> cls_Geom2dGcc_Circ2d2TanRad(mod, "Geom2dGcc_Circ2d2TanRad", "This class implements the algorithms used to create 2d circles tangent to one curve and a point/line/circle/curv and with a given radius. For each construction methods arguments are: - Two Qualified elements for tangency constrains. (for example EnclosedCirc if we want the solution inside the argument EnclosedCirc). - Two Reals. One (Radius) for the radius and the other (Tolerance) for the tolerance. Tolerance is only used for the limit cases. For example : We want to create a circle inside a circle C1 and inside a curve Cu2 with a radius Radius and a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the the following case : Cu2 is inside C1 and there is no intersection point between the two elements. with Tolerance we will give a solution if the lowest distance between C1 and Cu2 is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRad::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRad::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRad::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRad::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanRad::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanRad.def("Results", (void (Geom2dGcc_Circ2d2TanRad::*)(const GccAna_Circ2d2TanRad &)) &Geom2dGcc_Circ2d2TanRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanRad.def("Results", (void (Geom2dGcc_Circ2d2TanRad::*)(const Geom2dGcc_Circ2d2TanRadGeo &)) &Geom2dGcc_Circ2d2TanRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)() const) &Geom2dGcc_Circ2d2TanRad::IsDone, "This method returns True if the algorithm succeeded. Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d2TanRad.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanRad::*)() const) &Geom2dGcc_Circ2d2TanRad::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed. Exceptions StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Circ2d2TanRad.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Warning This indexing simply provides a means of consulting the solutions. The index values are not associated with these solutions outside the context of the algorithm object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRad.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanRad::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point, or - GccEnt_unqualified in certain limit cases where it is impossible to qualify the solution as enclosed, enclosing or outside. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanRad.def("Tangency1", [](Geom2dGcc_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRad.def("Tangency2", [](Geom2dGcc_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::IsTheSame1, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::IsTheSame2, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));

// Enums

}