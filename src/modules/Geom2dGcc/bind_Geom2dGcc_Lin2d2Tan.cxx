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
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_Position.hxx>
#include <Geom2dGcc_Lin2d2TanIter.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Lin2d2Tan.hxx>

void bind_Geom2dGcc_Lin2d2Tan(py::module &mod){

py::class_<Geom2dGcc_Lin2d2Tan> cls_Geom2dGcc_Lin2d2Tan(mod, "Geom2dGcc_Lin2d2Tan", "This class implements the algorithms used to create 2d lines tangent to 2 other elements which can be circles, curves or points. More than one argument must be a curve. Describes functions for building a 2D line: - tangential to 2 curves, or - tangential to a curve and passing through a point. A Lin2d2Tan object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Tolang"), py::arg("Param1"), py::arg("Param2"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Tolang"), py::arg("Param1"));

// Fields

// Methods
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2Tan::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2d2Tan::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2Tan::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2d2Tan::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2d2Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2d2Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2d2Tan.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2d2Tan::*)() const) &Geom2dGcc_Lin2d2Tan::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Lin2d2Tan.def("NbSolutions", (Standard_Integer (Geom2dGcc_Lin2d2Tan::*)() const) &Geom2dGcc_Lin2d2Tan::NbSolutions, "Returns the number of lines, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.R");
cls_Geom2dGcc_Lin2d2Tan.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2d2Tan::*)(const Standard_Integer) const) &Geom2dGcc_Lin2d2Tan::ThisSolution, "Returns a line, representing the solution of index Index computed by this algorithm. Warning This indexing simply provides a means of consulting the solutions. The index values are not associated with these solutions outside the context of the algorithm object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Lin2d2Tan.def("WhichQualifier", (void (Geom2dGcc_Lin2d2Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Lin2d2Tan::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Lin2d2Tan.def("Tangency1", [](Geom2dGcc_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2d2Tan.def("Tangency2", [](Geom2dGcc_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}