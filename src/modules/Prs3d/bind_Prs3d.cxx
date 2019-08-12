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
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Drawer.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d.hxx>

void bind_Prs3d(py::module &mod){

py::class_<Prs3d, std::unique_ptr<Prs3d, Deleter<Prs3d>>> cls_Prs3d(mod, "Prs3d", "The Prs3d package provides the following services - a presentation object (the context for all modifications to the display, its presentation will be displayed in every view of an active viewer) - an attribute manager governing how objects such as color, width, and type of line are displayed; these are generic objects, whereas those in StdPrs are specific geometries and topologies. - generic algorithms providing default settings for objects such as points, curves, surfaces and shapes - a root object which provides the abstract framework for the DsgPrs definitions at work in display of dimensions, relations and trihedra.");

// Constructors

// Fields

// Methods
// cls_Prs3d.def_static("operator new_", (void * (*)(size_t)) &Prs3d::operator new, "None", py::arg("theSize"));
// cls_Prs3d.def_static("operator delete_", (void (*)(void *)) &Prs3d::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d::operator new[], "None", py::arg("theSize"));
// cls_Prs3d.def_static("operator delete[]_", (void (*)(void *)) &Prs3d::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d.def_static("MatchSegment_", [](const Standard_Real X, const Standard_Real Y, const Standard_Real Z, const Standard_Real aDistance, const gp_Pnt & p1, const gp_Pnt & p2, Standard_Real & dist){ Standard_Boolean rv = Prs3d::MatchSegment(X, Y, Z, aDistance, p1, p2, dist); return std::tuple<Standard_Boolean, Standard_Real &>(rv, dist); }, "draws an arrow at a given location, with respect to a given direction.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("p1"), py::arg("p2"), py::arg("dist"));
cls_Prs3d.def_static("GetDeflection_", (Standard_Real (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &Prs3d::GetDeflection, "Computes the absolute deflection value depending on the type of deflection in theDrawer: Aspect_TOD_RELATIVE: the absolute deflection is computed using the relative deviation coefficient from theDrawer and the shape's bounding box; Aspect_TOD_ABSOLUTE: the maximal chordial deviation from theDrawer is returned. In case of the type of deflection in theDrawer computed relative deflection for shape is stored as absolute deflection. It is necessary to use it later on for sub-shapes. This function should always be used to compute the deflection value for building discrete representations of the shape (triangualtion, wireframe) to avoid incosistencies between different representations of the shape and undesirable visual artifacts.", py::arg("theShape"), py::arg("theDrawer"));
cls_Prs3d.def_static("PrimitivesFromPolylines_", (opencascade::handle<Graphic3d_ArrayOfPrimitives> (*)(const Prs3d_NListOfSequenceOfPnt &)) &Prs3d::PrimitivesFromPolylines, "Assembles array of primitives for sequence of polylines.", py::arg("thePoints"));
cls_Prs3d.def_static("AddPrimitivesGroup_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, Prs3d_NListOfSequenceOfPnt &)) &Prs3d::AddPrimitivesGroup, "Add primitives into new group in presentation and clear the list of polylines.", py::arg("thePrs"), py::arg("theAspect"), py::arg("thePolylines"));

// Enums

}