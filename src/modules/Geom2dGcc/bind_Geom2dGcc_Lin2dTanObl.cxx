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
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom2dGcc_Lin2dTanOblIter.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Lin2dTanObl.hxx>

void bind_Geom2dGcc_Lin2dTanObl(py::module &mod){

py::class_<Geom2dGcc_Lin2dTanObl> cls_Geom2dGcc_Lin2dTanObl(mod, "Geom2dGcc_Lin2dTanObl", "This class implements the algorithms used to create 2d line tangent to a curve QualifiedCurv and doing an angle Angle with a line TheLin. The angle must be in Radian. Describes functions for building a 2D line making a given angle with a line and tangential to a curve. A Lin2dTanObl object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Lin2dTanObl.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("TolAng"), py::arg("Angle"));
cls_Geom2dGcc_Lin2dTanObl.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("TolAng"), py::arg("Param1"), py::arg("Angle"));

// Fields

// Methods
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanObl::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2dTanObl::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanObl::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2dTanObl::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2dTanObl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2dTanObl::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2dTanObl.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Lin2dTanObl.def("NbSolutions", (Standard_Integer (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::NbSolutions, "Returns the number of lines, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Lin2dTanObl.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2dTanObl::*)(const Standard_Integer) const) &Geom2dGcc_Lin2dTanObl::ThisSolution, "Returns a line, representing the solution of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Lin2dTanObl.def("WhichQualifier", (void (Geom2dGcc_Lin2dTanObl::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Lin2dTanObl::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the argument, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Lin2dTanObl.def("Tangency1", [](Geom2dGcc_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanObl.def("Intersection2", [](Geom2dGcc_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns the point of intersection PntSol between the solution of index Index and the second argument (the line) of this algorithm. ParSol is the parameter of the point PntSol on the solution. ParArg is the parameter of the point PntSol on the second argument (the line). Exceptions StdFail_NotDone if the construction fails. Geom2dGcc_IsParallel if the solution and the second argument (the line) are parallel. Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
// cls_Geom2dGcc_Lin2dTanObl.def("IsParallel2", (Standard_Boolean (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::IsParallel2, "Returns true if the line and the solution are parallel. This is the case when the angle given at the time of construction is equal to 0 or Pi. Exceptions StdFail_NotDone if the construction fails.");

// Enums

}