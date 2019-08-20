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
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <DsgPrs_FilletRadiusPresentation.hxx>

void bind_DsgPrs_FilletRadiusPresentation(py::module &mod){

py::class_<DsgPrs_FilletRadiusPresentation, std::unique_ptr<DsgPrs_FilletRadiusPresentation>> cls_DsgPrs_FilletRadiusPresentation(mod, "DsgPrs_FilletRadiusPresentation", "A framework for displaying radii of fillets.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_FilletRadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_FilletRadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_FilletRadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_FilletRadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_FilletRadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_FilletRadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_FilletRadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & aPresentation, const opencascade::handle<Prs3d_Drawer> & aDrawer, const Standard_Real thevalue, const TCollection_ExtendedString & aText, const gp_Pnt & aPosition, const gp_Dir & aNormalDir, const gp_Pnt & aBasePnt, const gp_Pnt & aFirstPoint, const gp_Pnt & aSecondPoint, const gp_Pnt & aCenter, const DsgPrs_ArrowSide ArrowPrs, const Standard_Boolean drawRevers, gp_Pnt & DrawPosition, gp_Pnt & EndOfArrow, opencascade::handle<Geom_TrimmedCurve> & TrimCurve, Standard_Boolean & HasCircle){ DsgPrs_FilletRadiusPresentation::Add(aPresentation, aDrawer, thevalue, aText, aPosition, aNormalDir, aBasePnt, aFirstPoint, aSecondPoint, aCenter, ArrowPrs, drawRevers, DrawPosition, EndOfArrow, TrimCurve, HasCircle); return HasCircle; }, "Adds a display of the radius of a fillet to the presentation aPresentation. The display ttributes defined by the attribute manager aDrawer. the value specifies the length of the radius.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("thevalue"), py::arg("aText"), py::arg("aPosition"), py::arg("aNormalDir"), py::arg("aBasePnt"), py::arg("aFirstPoint"), py::arg("aSecondPoint"), py::arg("aCenter"), py::arg("ArrowPrs"), py::arg("drawRevers"), py::arg("DrawPosition"), py::arg("EndOfArrow"), py::arg("TrimCurve"), py::arg("HasCircle"));

// Enums

}