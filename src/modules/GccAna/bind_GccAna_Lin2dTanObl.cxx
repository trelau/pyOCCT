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
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Lin2dTanObl.hxx>

void bind_GccAna_Lin2dTanObl(py::module &mod){

py::class_<GccAna_Lin2dTanObl> cls_GccAna_Lin2dTanObl(mod, "GccAna_Lin2dTanObl", "This class implements the algorithms used to create 2d line tangent to a circle or a point and making an angle with a line. The angle is in radians. The origin of the solution is the tangency point with the first argument. Its direction is making an angle Angle with the second argument.");

// Constructors
cls_GccAna_Lin2dTanObl.def(py::init<const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("ThePoint"), py::arg("TheLine"), py::arg("TheAngle"));
cls_GccAna_Lin2dTanObl.def(py::init<const GccEnt_QualifiedCirc &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLine"), py::arg("TheAngle"));

// Fields

// Methods
// cls_GccAna_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t)) &GccAna_Lin2dTanObl::operator new, "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanObl.def_static("operator delete_", (void (*)(void *)) &GccAna_Lin2dTanObl::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanObl.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Lin2dTanObl::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Lin2dTanObl.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Lin2dTanObl::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Lin2dTanObl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Lin2dTanObl.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Lin2dTanObl::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Lin2dTanObl.def("IsDone", (Standard_Boolean (GccAna_Lin2dTanObl::*)() const) &GccAna_Lin2dTanObl::IsDone, "Returns True if the algorithm succeeded. Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_GccAna_Lin2dTanObl.def("NbSolutions", (Standard_Integer (GccAna_Lin2dTanObl::*)() const) &GccAna_Lin2dTanObl::NbSolutions, "Returns the number of of lines, representing solutions computed by this algorithm. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Lin2dTanObl.def("ThisSolution", (gp_Lin2d (GccAna_Lin2dTanObl::*)(const Standard_Integer) const) &GccAna_Lin2dTanObl::ThisSolution, "Returns the solution number Index. Be careful: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_GccAna_Lin2dTanObl.def("WhichQualifier", (void (GccAna_Lin2dTanObl::*)(const Standard_Integer, GccEnt_Position &) const) &GccAna_Lin2dTanObl::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the argument, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_GccAna_Lin2dTanObl.def("Tangency1", [](GccAna_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point ParSol on the solution curv. ParArg is the intrinsic parameter of the point ParArg on the argument curv. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Lin2dTanObl.def("Intersection2", [](GccAna_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the intersection between the result number Index and the third argument. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}