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
#include <BRepFill_MultiLine.hxx>
#include <Standard_TypeDef.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <BRepFill_ComputeCLine.hxx>

void bind_BRepFill_ComputeCLine(py::module &mod){

py::class_<BRepFill_ComputeCLine> cls_BRepFill_ComputeCLine(mod, "BRepFill_ComputeCLine", "None");

// Constructors
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &>(), py::arg("Line"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
cls_BRepFill_ComputeCLine.def(py::init<>());
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));

// Fields

// Methods
// cls_BRepFill_ComputeCLine.def_static("operator new_", (void * (*)(size_t)) &BRepFill_ComputeCLine::operator new, "None", py::arg("theSize"));
// cls_BRepFill_ComputeCLine.def_static("operator delete_", (void (*)(void *)) &BRepFill_ComputeCLine::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_ComputeCLine.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_ComputeCLine::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_ComputeCLine.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_ComputeCLine::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_ComputeCLine.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_ComputeCLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_ComputeCLine.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_ComputeCLine::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_ComputeCLine.def("Perform", (void (BRepFill_ComputeCLine::*)(const BRepFill_MultiLine &)) &BRepFill_ComputeCLine::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_BRepFill_ComputeCLine.def("SetDegrees", (void (BRepFill_ComputeCLine::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_ComputeCLine::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_BRepFill_ComputeCLine.def("SetTolerances", (void (BRepFill_ComputeCLine::*)(const Standard_Real, const Standard_Real)) &BRepFill_ComputeCLine::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepFill_ComputeCLine.def("SetConstraints", (void (BRepFill_ComputeCLine::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &BRepFill_ComputeCLine::SetConstraints, "Changes the constraints of the approximation.", py::arg("FirstC"), py::arg("LastC"));
cls_BRepFill_ComputeCLine.def("SetMaxSegments", (void (BRepFill_ComputeCLine::*)(const Standard_Integer)) &BRepFill_ComputeCLine::SetMaxSegments, "Changes the max number of segments, which is allowed for cutting.", py::arg("theMaxSegments"));
cls_BRepFill_ComputeCLine.def("IsAllApproximated", (Standard_Boolean (BRepFill_ComputeCLine::*)() const) &BRepFill_ComputeCLine::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_BRepFill_ComputeCLine.def("IsToleranceReached", (Standard_Boolean (BRepFill_ComputeCLine::*)() const) &BRepFill_ComputeCLine::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_BRepFill_ComputeCLine.def("Error", [](BRepFill_ComputeCLine &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_BRepFill_ComputeCLine.def("NbMultiCurves", (Standard_Integer (BRepFill_ComputeCLine::*)() const) &BRepFill_ComputeCLine::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_BRepFill_ComputeCLine.def("Value", [](BRepFill_ComputeCLine &self) -> AppParCurves_MultiCurve { return self.Value(); });
cls_BRepFill_ComputeCLine.def("Value", (AppParCurves_MultiCurve (BRepFill_ComputeCLine::*)(const Standard_Integer) const) &BRepFill_ComputeCLine::Value, "returns the approximation MultiCurve of range <Index>.", py::arg("Index"));
cls_BRepFill_ComputeCLine.def("Parameters", [](BRepFill_ComputeCLine &self, const Standard_Integer Index, Standard_Real & firstp, Standard_Real & lastp){ self.Parameters(Index, firstp, lastp); return std::tuple<Standard_Real &, Standard_Real &>(firstp, lastp); }, "None", py::arg("Index"), py::arg("firstp"), py::arg("lastp"));

// Enums

}