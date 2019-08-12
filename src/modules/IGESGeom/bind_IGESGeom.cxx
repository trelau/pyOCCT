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
#include <IGESGeom_Protocol.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <IGESGeom_ConicArc.hxx>
#include <IGESGeom_CopiousData.hxx>
#include <IGESGeom_Plane.hxx>
#include <IGESGeom_Line.hxx>
#include <IGESGeom_SplineCurve.hxx>
#include <IGESGeom_SplineSurface.hxx>
#include <IGESGeom_Point.hxx>
#include <IGESGeom_RuledSurface.hxx>
#include <IGESGeom_SurfaceOfRevolution.hxx>
#include <IGESGeom_TabulatedCylinder.hxx>
#include <IGESGeom_Direction.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESGeom_Flash.hxx>
#include <IGESGeom_BSplineCurve.hxx>
#include <IGESGeom_BSplineSurface.hxx>
#include <IGESGeom_OffsetCurve.hxx>
#include <IGESGeom_OffsetSurface.hxx>
#include <IGESGeom_Boundary.hxx>
#include <IGESGeom_CurveOnSurface.hxx>
#include <IGESGeom_BoundedSurface.hxx>
#include <IGESGeom_TrimmedSurface.hxx>
#include <IGESGeom_ToolCircularArc.hxx>
#include <IGESGeom_ToolCompositeCurve.hxx>
#include <IGESGeom_ToolConicArc.hxx>
#include <IGESGeom_ToolCopiousData.hxx>
#include <IGESGeom_ToolPlane.hxx>
#include <IGESGeom_ToolLine.hxx>
#include <IGESGeom_ToolSplineCurve.hxx>
#include <IGESGeom_ToolSplineSurface.hxx>
#include <IGESGeom_ToolPoint.hxx>
#include <IGESGeom_ToolRuledSurface.hxx>
#include <IGESGeom_ToolSurfaceOfRevolution.hxx>
#include <IGESGeom_ToolTabulatedCylinder.hxx>
#include <IGESGeom_ToolDirection.hxx>
#include <IGESGeom_ToolTransformationMatrix.hxx>
#include <IGESGeom_ToolFlash.hxx>
#include <IGESGeom_ToolBSplineCurve.hxx>
#include <IGESGeom_ToolBSplineSurface.hxx>
#include <IGESGeom_ToolOffsetCurve.hxx>
#include <IGESGeom_ToolOffsetSurface.hxx>
#include <IGESGeom_ToolBoundary.hxx>
#include <IGESGeom_ToolCurveOnSurface.hxx>
#include <IGESGeom_ToolBoundedSurface.hxx>
#include <IGESGeom_ToolTrimmedSurface.hxx>
#include <IGESGeom_ReadWriteModule.hxx>
#include <IGESGeom_GeneralModule.hxx>
#include <IGESGeom_SpecificModule.hxx>
#include <IGESGeom.hxx>

void bind_IGESGeom(py::module &mod){

py::class_<IGESGeom, std::unique_ptr<IGESGeom, Deleter<IGESGeom>>> cls_IGESGeom(mod, "IGESGeom", "This package consists of B-Rep and CSG Solid entities");

// Constructors

// Fields

// Methods
// cls_IGESGeom.def_static("operator new_", (void * (*)(size_t)) &IGESGeom::operator new, "None", py::arg("theSize"));
// cls_IGESGeom.def_static("operator delete_", (void (*)(void *)) &IGESGeom::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom.def_static("Init_", (void (*)()) &IGESGeom::Init, "Prepares dymanic data (Protocol, Modules) for this package");
cls_IGESGeom.def_static("Protocol_", (opencascade::handle<IGESGeom_Protocol> (*)()) &IGESGeom::Protocol, "Returns the Protocol for this Package");

// Enums

}