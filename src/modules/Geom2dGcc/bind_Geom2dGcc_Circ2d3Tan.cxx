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
#include <GccAna_Circ2d3Tan.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2d3Tan.hxx>

void bind_Geom2dGcc_Circ2d3Tan(py::module &mod){

py::class_<Geom2dGcc_Circ2d3Tan, std::unique_ptr<Geom2dGcc_Circ2d3Tan, Deleter<Geom2dGcc_Circ2d3Tan>>> cls_Geom2dGcc_Circ2d3Tan(mod, "Geom2dGcc_Circ2d3Tan", "This class implements the algorithms used to create 2d circles tangent to 3 points/lines/circles/ curves with one curve or more. The arguments of all construction methods are : - The three qualifiied elements for the tangency constrains (QualifiedCirc, QualifiedLine, Qualifiedcurv, Points). - A parameter for each QualifiedCurv. Describes functions for building a 2D circle: - tangential to 3 curves, or - tangential to 2 curves and passing through a point, or - tangential to a curve and passing through 2 points, or - passing through 3 points. A Circ2d3Tan object provides a framework for: - defining the construction of 2D circles(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point1"), py::arg("Point2"), py::arg("Tolerance"), py::arg("Param1"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3Tan::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d3Tan::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3Tan::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d3Tan::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d3Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d3Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d3Tan.def("Results", (void (Geom2dGcc_Circ2d3Tan::*)(const GccAna_Circ2d3Tan &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Geom2dGcc_Circ2d3Tan::Results, "None", py::arg("Circ"), py::arg("Rank1"), py::arg("Rank2"), py::arg("Rank3"));
cls_Geom2dGcc_Circ2d3Tan.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)() const) &Geom2dGcc_Circ2d3Tan::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d3Tan.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d3Tan::*)() const) &Geom2dGcc_Circ2d3Tan::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed.");
cls_Geom2dGcc_Circ2d3Tan.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("WhichQualifier", (void (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d3Tan::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"), py::arg("Qualif3"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency1", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency2", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency3", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency3(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the third argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame1, "Returns True if the solution is equal to the first argument.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame2, "Returns True if the solution is equal to the second argument.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame3", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame3, "Returns True if the solution is equal to the third argument. If Rarg is the radius of the first, second or third argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));

// Enums

}