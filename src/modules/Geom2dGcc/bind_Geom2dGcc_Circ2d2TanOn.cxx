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
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Point.hxx>
#include <GccAna_Circ2d2TanOn.hxx>
#include <Geom2dGcc_Circ2d2TanOnGeo.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2d2TanOn.hxx>

void bind_Geom2dGcc_Circ2d2TanOn(py::module &mod){

py::class_<Geom2dGcc_Circ2d2TanOn> cls_Geom2dGcc_Circ2d2TanOn(mod, "Geom2dGcc_Circ2d2TanOn", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curve. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments. - The center line. - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"));
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point"), py::arg("OnCurve"), py::arg("Tolerance"), py::arg("Param1"), py::arg("ParamOn"));
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnCurve"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOn::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOn::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOn::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOn::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOn::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOn::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOn.def("Results", (void (Geom2dGcc_Circ2d2TanOn::*)(const GccAna_Circ2d2TanOn &)) &Geom2dGcc_Circ2d2TanOn::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanOn.def("Results", (void (Geom2dGcc_Circ2d2TanOn::*)(const Geom2dGcc_Circ2d2TanOnGeo &)) &Geom2dGcc_Circ2d2TanOn::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)() const) &Geom2dGcc_Circ2d2TanOn::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d2TanOn.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanOn::*)() const) &Geom2dGcc_Circ2d2TanOn::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed.");
cls_Geom2dGcc_Circ2d2TanOn.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Exceptions Standard_OutOfRange if Index is less than or equal to zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOn.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOn::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified). Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOn.def("Tangency1", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("Tangency2", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns the center PntSol of the solution of index Index computed by this algorithm. ParArg is the parameter of the point PntSol on the third argument. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::IsTheSame1, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::IsTheSame2, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));

// Enums

}