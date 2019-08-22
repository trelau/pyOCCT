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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFi2d_FilletAlgo.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_FilletPoint(py::module &mod){

py::class_<FilletPoint> cls_FilletPoint(mod, "FilletPoint", "Private class. Corresponds to the point on the first curve, computed fillet function and derivative on it.");

// Constructors
// cls_FilletPoint.def(py::init<const Standard_Real>(), py::arg("theParam"));

// Fields

// Methods
cls_FilletPoint.def("setParam", (void (FilletPoint::*)(Standard_Real)) &FilletPoint::setParam, "Changes the point position by changing point parameter on the first curve.", py::arg("theParam"));
cls_FilletPoint.def("getParam", (Standard_Real (FilletPoint::*)() const) &FilletPoint::getParam, "Returns the point parameter on the first curve.");
cls_FilletPoint.def("getNBValues", (Standard_Integer (FilletPoint::*)()) &FilletPoint::getNBValues, "Returns number of found values of function in this point.");
cls_FilletPoint.def("getValue", (Standard_Real (FilletPoint::*)(int)) &FilletPoint::getValue, "Returns value of function in this point.", py::arg("theIndex"));
cls_FilletPoint.def("getDiff", (Standard_Real (FilletPoint::*)(int)) &FilletPoint::getDiff, "Returns derivatives of function in this point.", py::arg("theIndex"));
cls_FilletPoint.def("isValid", (Standard_Boolean (FilletPoint::*)(int)) &FilletPoint::isValid, "Returns true if function is valid (rediuses vectors of fillet do not intersect any curve).", py::arg("theIndex"));
cls_FilletPoint.def("getNear", (int (FilletPoint::*)(int)) &FilletPoint::getNear, "Returns the index of the nearest value", py::arg("theIndex"));
cls_FilletPoint.def("setParam2", (void (FilletPoint::*)(const Standard_Real)) &FilletPoint::setParam2, "Defines the parameter of the projected point on the second curve.", py::arg("theParam2"));
cls_FilletPoint.def("getParam2", (Standard_Real (FilletPoint::*)()) &FilletPoint::getParam2, "Returns the parameter of the projected point on the second curve.");
cls_FilletPoint.def("setCenter", (void (FilletPoint::*)(const gp_Pnt2d)) &FilletPoint::setCenter, "Center of the fillet.", py::arg("thePoint"));
cls_FilletPoint.def("getCenter", (const gp_Pnt2d (FilletPoint::*)()) &FilletPoint::getCenter, "Center of the fillet.");
// cls_FilletPoint.def("appendValue", (void (FilletPoint::*)(Standard_Real, Standard_Boolean)) &FilletPoint::appendValue, "Appends value of the function.", py::arg("theValue"), py::arg("theValid"));
// cls_FilletPoint.def("calculateDiff", (Standard_Boolean (FilletPoint::*)(FilletPoint *)) &FilletPoint::calculateDiff, "Computes difference between this point and the given. Stores difference in myD.", py::arg(""));
// cls_FilletPoint.def("FilterPoints", (void (FilletPoint::*)(FilletPoint *)) &FilletPoint::FilterPoints, "Filters out the values and leaves the most optimal one.", py::arg(""));
// cls_FilletPoint.def("Copy", (FilletPoint * (FilletPoint::*)()) &FilletPoint::Copy, "Returns a pointer to created copy of the point warning: this is not the full copy! Copies only: myParam, myV, myD, myValid");
// cls_FilletPoint.def("hasSolution", (Standard_Integer (FilletPoint::*)(Standard_Real)) &FilletPoint::hasSolution, "Returns the index of the solution or zero if there is no solution", py::arg("theRadius"));
cls_FilletPoint.def("LowerValue", (Standard_Real (FilletPoint::*)()) &FilletPoint::LowerValue, "For debug only");
// cls_FilletPoint.def("remove", (void (FilletPoint::*)(Standard_Integer)) &FilletPoint::remove, "Removes the found value by the given index.", py::arg("theIndex"));

// Enums

}