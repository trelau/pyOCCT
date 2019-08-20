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
#include <Standard_TypeDef.hxx>
#include <GeomInt_IntSS.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <GeomInt_LineTool.hxx>
#include <GeomInt_WLApprox.hxx>
#include <GeomInt_ParameterAndOrientation.hxx>
#include <GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_ThePrmPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheImpPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheMultiLineOfWLApprox.hxx>
#include <GeomInt_TheMultiLineToolOfWLApprox.hxx>
#include <GeomInt_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_MyBSplGradientOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_ResConstraintOfMyGradientbisOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_ParFunctionOfMyGradientbisOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_MyGradientbisOfTheComputeLineOfWLApprox.hxx>
#include <GeomInt_TheComputeLineOfWLApprox.hxx>
#include <GeomInt_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt_ResConstraintOfMyGradientOfTheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt_ParFunctionOfMyGradientOfTheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt_MyGradientOfTheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt_TheComputeLineBezierOfWLApprox.hxx>
#include <GeomInt.hxx>

void bind_GeomInt(py::module &mod){

py::class_<GeomInt, std::unique_ptr<GeomInt>> cls_GeomInt(mod, "GeomInt", "Provides intersections on between two surfaces of Geom. The result are curves from Geom.");

// Constructors

// Fields

// Methods
// cls_GeomInt.def_static("operator new_", (void * (*)(size_t)) &GeomInt::operator new, "None", py::arg("theSize"));
// cls_GeomInt.def_static("operator delete_", (void (*)(void *)) &GeomInt::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt::operator new[], "None", py::arg("theSize"));
// cls_GeomInt.def_static("operator delete[]_", (void (*)(void *)) &GeomInt::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt.def_static("AdjustPeriodic_", [](const Standard_Real thePar, const Standard_Real theParMin, const Standard_Real theParMax, const Standard_Real thePeriod, Standard_Real & theNewPar, Standard_Real & theOffset, const Standard_Real theEps){ Standard_Boolean rv = GeomInt::AdjustPeriodic(thePar, theParMin, theParMax, thePeriod, theNewPar, theOffset, theEps); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theNewPar, theOffset); }, "Adjusts the parameter <thePar> to the range [theParMin, theParMax]", py::arg("thePar"), py::arg("theParMin"), py::arg("theParMax"), py::arg("thePeriod"), py::arg("theNewPar"), py::arg("theOffset"), py::arg("theEps"));

// Enums

}