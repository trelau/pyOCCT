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
#include <Prs3d_LineAspect.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <DsgPrs_XYZAxisPresentation.hxx>

void bind_DsgPrs_XYZAxisPresentation(py::module &mod){

py::class_<DsgPrs_XYZAxisPresentation, std::unique_ptr<DsgPrs_XYZAxisPresentation, Deleter<DsgPrs_XYZAxisPresentation>>> cls_DsgPrs_XYZAxisPresentation(mod, "DsgPrs_XYZAxisPresentation", "A framework for displaying the axes of an XYZ trihedron.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_XYZAxisPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_XYZAxisPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_XYZAxisPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_XYZAxisPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_XYZAxisPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_XYZAxisPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_XYZAxisPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, const gp_Dir &, const Standard_Real, const Standard_CString, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_XYZAxisPresentation::Add, "Draws each axis of a trihedron displayed in the presentation aPresentation and with lines shown by the values of aLineAspect. Each axis is defined by: - the first and last points aPfirst and aPlast - the direction aDir and - the value aVal which provides a value for length. The value for length is provided so that the trihedron can vary in length relative to the scale of shape display. Each axis will be identified as X, Y, or Z by the text aText.", py::arg("aPresentation"), py::arg("anLineAspect"), py::arg("aDir"), py::arg("aVal"), py::arg("aText"), py::arg("aPfirst"), py::arg("aPlast"));
cls_DsgPrs_XYZAxisPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, const opencascade::handle<Prs3d_ArrowAspect> &, const opencascade::handle<Prs3d_TextAspect> &, const gp_Dir &, const Standard_Real, const Standard_CString, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_XYZAxisPresentation::Add, "draws the presentation X ,Y ,Z axis", py::arg("aPresentation"), py::arg("aLineAspect"), py::arg("anArrowAspect"), py::arg("aTextAspect"), py::arg("aDir"), py::arg("aVal"), py::arg("aText"), py::arg("aPfirst"), py::arg("aPlast"));

// Enums

}