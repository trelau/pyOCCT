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
#include <NCollection_Array1.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <AppCont_Function.hxx>

void bind_AppCont_Function(py::module &mod){

py::class_<AppCont_Function> cls_AppCont_Function(mod, "AppCont_Function", "Class describing a continous 3d and/or function f(u). This class must be provided by the user to use the approximation algorithm FittingCurve.");

// Fields

// Methods
cls_AppCont_Function.def("GetNumberOfPoints", [](AppCont_Function &self, Standard_Integer & theNbPnt, Standard_Integer & theNbPnt2d){ self.GetNumberOfPoints(theNbPnt, theNbPnt2d); return std::tuple<Standard_Integer &, Standard_Integer &>(theNbPnt, theNbPnt2d); }, "Get number of 3d and 2d points returned by 'Value' and 'D1' functions.", py::arg("theNbPnt"), py::arg("theNbPnt2d"));
cls_AppCont_Function.def("GetNbOf3dPoints", (Standard_Integer (AppCont_Function::*)() const) &AppCont_Function::GetNbOf3dPoints, "Get number of 3d points returned by 'Value' and 'D1' functions.");
cls_AppCont_Function.def("GetNbOf2dPoints", (Standard_Integer (AppCont_Function::*)() const) &AppCont_Function::GetNbOf2dPoints, "Get number of 2d points returned by 'Value' and 'D1' functions.");
cls_AppCont_Function.def("FirstParameter", (Standard_Real (AppCont_Function::*)() const) &AppCont_Function::FirstParameter, "Returns the first parameter of the function.");
cls_AppCont_Function.def("LastParameter", (Standard_Real (AppCont_Function::*)() const) &AppCont_Function::LastParameter, "Returns the last parameter of the function.");
cls_AppCont_Function.def("Value", (Standard_Boolean (AppCont_Function::*)(const Standard_Real, NCollection_Array1<gp_Pnt2d> &, NCollection_Array1<gp_Pnt> &) const) &AppCont_Function::Value, "Returns the point at parameter <theU>.", py::arg("theU"), py::arg("thePnt2d"), py::arg("thePnt"));
cls_AppCont_Function.def("D1", (Standard_Boolean (AppCont_Function::*)(const Standard_Real, NCollection_Array1<gp_Vec2d> &, NCollection_Array1<gp_Vec> &) const) &AppCont_Function::D1, "Returns the derivative at parameter <theU>.", py::arg("theU"), py::arg("theVec2d"), py::arg("theVec"));
cls_AppCont_Function.def("PeriodInformation", [](AppCont_Function &self, const Standard_Integer a0, Standard_Boolean & IsPeriodic, Standard_Real & thePeriod){ self.PeriodInformation(a0, IsPeriodic, thePeriod); return std::tuple<Standard_Boolean &, Standard_Real &>(IsPeriodic, thePeriod); }, "Return information about peridicity in output paramateters space.", py::arg(""), py::arg("IsPeriodic"), py::arg("thePeriod"));

// Enums

}