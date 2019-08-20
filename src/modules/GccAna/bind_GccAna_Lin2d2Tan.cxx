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
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Lin2d2Tan.hxx>

void bind_GccAna_Lin2d2Tan(py::module &mod){

py::class_<GccAna_Lin2d2Tan, std::unique_ptr<GccAna_Lin2d2Tan>> cls_GccAna_Lin2d2Tan(mod, "GccAna_Lin2d2Tan", "This class implements the algorithms used to create 2d lines tangent to 2 other elements which can be circles or points. Describes functions for building a 2D line: - tangential to 2 circles, or - tangential to a circle and passing through a point, or - passing through 2 points. A Lin2d2Tan object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and consulting the result(s). Some constructors may check the type of the qualified argument and raise BadQualifier Error in case of incorrect couple (qualifier, curv). For example: 'EnclosedCirc'.");

// Constructors
cls_GccAna_Lin2d2Tan.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("ThePoint1"), py::arg("ThePoint2"), py::arg("Tolerance"));
cls_GccAna_Lin2d2Tan.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Tolerance"));
cls_GccAna_Lin2d2Tan.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GccAna_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t)) &GccAna_Lin2d2Tan::operator new, "None", py::arg("theSize"));
// cls_GccAna_Lin2d2Tan.def_static("operator delete_", (void (*)(void *)) &GccAna_Lin2d2Tan::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Lin2d2Tan.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Lin2d2Tan::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Lin2d2Tan.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Lin2d2Tan::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Lin2d2Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Lin2d2Tan.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Lin2d2Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Lin2d2Tan.def("IsDone", (Standard_Boolean (GccAna_Lin2d2Tan::*)() const) &GccAna_Lin2d2Tan::IsDone, "This method returns true when there is a solution and false in the other cases.");
cls_GccAna_Lin2d2Tan.def("NbSolutions", (Standard_Integer (GccAna_Lin2d2Tan::*)() const) &GccAna_Lin2d2Tan::NbSolutions, "This method returns the number of solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Lin2d2Tan.def("ThisSolution", (gp_Lin2d (GccAna_Lin2d2Tan::*)(const Standard_Integer) const) &GccAna_Lin2d2Tan::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Raises OutOfRange is raised if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"));
cls_GccAna_Lin2d2Tan.def("WhichQualifier", (void (GccAna_Lin2d2Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &GccAna_Lin2d2Tan::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_GccAna_Lin2d2Tan.def("Tangency1", [](GccAna_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Raises OutOfRange is raised if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Lin2d2Tan.def("Tangency2", [](GccAna_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point ParSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Raises OutOfRange is raised if Index is greater than the number of solutions. It raises NotDone if the algorithm failed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}