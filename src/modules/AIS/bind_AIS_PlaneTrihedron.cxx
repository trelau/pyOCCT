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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_PlaneTrihedron.hxx>
#include <Standard_Type.hxx>
#include <Geom_Plane.hxx>
#include <AIS_Line.hxx>
#include <AIS_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Quantity_Color.hxx>
#include <TCollection_AsciiString.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_PlaneTrihedron(py::module &mod){

py::class_<AIS_PlaneTrihedron, opencascade::handle<AIS_PlaneTrihedron>, AIS_InteractiveObject> cls_AIS_PlaneTrihedron(mod, "AIS_PlaneTrihedron", "To construct a selectable 2d axis system in a 3d drawing. This can be placed anywhere in the 3d system, and provides a coordinate system for drawing curves and shapes in a plane. There are 3 selection modes: - mode 0 selection of the whole plane 'trihedron' - mode 1 selection of the origin of the plane 'trihedron' - mode 2 selection of the axes. Warning For the presentation of planes and trihedra, the millimetre is default unit of length, and 100 the default value for the representation of the axes. If you modify these dimensions, you must temporarily recover the Drawer object. From inside it, take the Aspects in which the values for length are stocked, for example, PlaneAspect for planes and LineAspect for trihedra. Change these values and recalculate the presentation.");

// Constructors
cls_AIS_PlaneTrihedron.def(py::init<const opencascade::handle<Geom_Plane> &>(), py::arg("aPlane"));

// Fields

// Methods
cls_AIS_PlaneTrihedron.def_static("get_type_name_", (const char * (*)()) &AIS_PlaneTrihedron::get_type_name, "None");
cls_AIS_PlaneTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PlaneTrihedron::get_type_descriptor, "None");
cls_AIS_PlaneTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::DynamicType, "None");
cls_AIS_PlaneTrihedron.def("Component", (opencascade::handle<Geom_Plane> (AIS_PlaneTrihedron::*)()) &AIS_PlaneTrihedron::Component, "Returns the component specified in SetComponent.");
cls_AIS_PlaneTrihedron.def("SetComponent", (void (AIS_PlaneTrihedron::*)(const opencascade::handle<Geom_Plane> &)) &AIS_PlaneTrihedron::SetComponent, "Creates an instance of the component object aPlane.", py::arg("aPlane"));
cls_AIS_PlaneTrihedron.def("XAxis", (opencascade::handle<AIS_Line> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::XAxis, "Returns the 'XAxis'.");
cls_AIS_PlaneTrihedron.def("YAxis", (opencascade::handle<AIS_Line> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::YAxis, "Returns the 'YAxis'.");
cls_AIS_PlaneTrihedron.def("Position", (opencascade::handle<AIS_Point> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Position, "Returns the point of origin of the plane trihedron.");
cls_AIS_PlaneTrihedron.def("SetLength", (void (AIS_PlaneTrihedron::*)(const Standard_Real)) &AIS_PlaneTrihedron::SetLength, "Sets the length of the X and Y axes.", py::arg("theLength"));
cls_AIS_PlaneTrihedron.def("GetLength", (Standard_Real (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::GetLength, "Returns the length of X and Y axes.");
cls_AIS_PlaneTrihedron.def("AcceptDisplayMode", (Standard_Boolean (AIS_PlaneTrihedron::*)(const Standard_Integer) const) &AIS_PlaneTrihedron::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid.", py::arg("aMode"));
cls_AIS_PlaneTrihedron.def("Compute", (void (AIS_PlaneTrihedron::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_PlaneTrihedron::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_PlaneTrihedron.def("Signature", (Standard_Integer (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Signature, "None");
cls_AIS_PlaneTrihedron.def("Type", (AIS_KindOfInteractive (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Type, "Returns datum as the type of Interactive Object.");
cls_AIS_PlaneTrihedron.def("SetColor", (void (AIS_PlaneTrihedron::*)(const Quantity_Color &)) &AIS_PlaneTrihedron::SetColor, "Allows you to provide settings for the color aColor.", py::arg("theColor"));
cls_AIS_PlaneTrihedron.def("SetXLabel", (void (AIS_PlaneTrihedron::*)(const TCollection_AsciiString &)) &AIS_PlaneTrihedron::SetXLabel, "None", py::arg("theLabel"));
cls_AIS_PlaneTrihedron.def("SetYLabel", (void (AIS_PlaneTrihedron::*)(const TCollection_AsciiString &)) &AIS_PlaneTrihedron::SetYLabel, "None", py::arg("theLabel"));

// Enums

}