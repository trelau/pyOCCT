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
#include <Geom2dGcc_QCurve.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Circ2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <GccEnt_Position.hxx>
#include <Geom2dGcc_Circ2d2TanOnIter.hxx>

void bind_Geom2dGcc_Circ2d2TanOnIter(py::module &mod){

py::class_<Geom2dGcc_Circ2d2TanOnIter, std::unique_ptr<Geom2dGcc_Circ2d2TanOnIter, Deleter<Geom2dGcc_Circ2d2TanOnIter>>> cls_Geom2dGcc_Circ2d2TanOnIter(mod, "Geom2dGcc_Circ2d2TanOnIter", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curv. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments. - The center line. - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOnIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::ThisSolution, "Returns the solution. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOnIter::*)(GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOnIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("Tangency1", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("Tangency2", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(ParArg, PntSol); return ParArg; }, "Returns information about the center (on the curv) of the result and the third argument. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsTheSame1, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsTheSame2, "It raises NotDone if the construction algorithm didn't succeed.");

// Enums

}