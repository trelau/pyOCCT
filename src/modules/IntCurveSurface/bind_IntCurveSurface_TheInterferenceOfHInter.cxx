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
#include <Intf_Interference.hxx>
#include <Standard.hxx>
#include <IntCurveSurface_ThePolygonOfHInter.hxx>
#include <IntCurveSurface_ThePolyhedronOfHInter.hxx>
#include <gp_Lin.hxx>
#include <Intf_Array1OfLin.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <IntCurveSurface_TheInterferenceOfHInter.hxx>

void bind_IntCurveSurface_TheInterferenceOfHInter(py::module &mod){

py::class_<IntCurveSurface_TheInterferenceOfHInter, std::unique_ptr<IntCurveSurface_TheInterferenceOfHInter>, Intf_Interference> cls_IntCurveSurface_TheInterferenceOfHInter(mod, "IntCurveSurface_TheInterferenceOfHInter", "None");

// Constructors
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<>());
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("thePolyg"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("theLin"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("theLins"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));

// Fields

// Methods
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheInterferenceOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheInterferenceOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheInterferenceOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Interference", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Interference", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"));

// Enums

}