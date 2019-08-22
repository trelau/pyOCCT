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
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_Curve.hxx>

void bind_VrmlConverter_Curve(py::module &mod){

py::class_<VrmlConverter_Curve> cls_VrmlConverter_Curve(mod, "VrmlConverter_Curve", "Curve - computes the presentation of objects to be seen as curves (the computation will be made with a constant number of points), converts this one into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer of Drawer class (VrmlConverter). This kind of the presentation is converted into IndexedLineSet ( VRML ).");

// Constructors

// Fields

// Methods
// cls_VrmlConverter_Curve.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_Curve::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_Curve.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_Curve::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_Curve::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_Curve.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const opencascade::handle<VrmlConverter_Drawer> &, Standard_OStream &)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer.", py::arg("aCurve"), py::arg("aDrawer"), py::arg("anOStream"));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<VrmlConverter_Drawer> &, Standard_OStream &)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer. The drawing will be limited between the points of parameter U1 and U2.", py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"), py::arg("anOStream"));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, Standard_OStream &, const Standard_Integer)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is the current aspect. The drawing will be limited between the points of parameter U1 and U2. aNbPoints defines number of points on one interval.", py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("anOStream"), py::arg("aNbPoints"));

// Enums

}