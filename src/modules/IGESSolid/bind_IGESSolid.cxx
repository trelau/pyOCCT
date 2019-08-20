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
#include <IGESSolid_Protocol.hxx>
#include <IGESSolid_Block.hxx>
#include <IGESSolid_RightAngularWedge.hxx>
#include <IGESSolid_Cylinder.hxx>
#include <IGESSolid_ConeFrustum.hxx>
#include <IGESSolid_Sphere.hxx>
#include <IGESSolid_Torus.hxx>
#include <IGESSolid_SolidOfRevolution.hxx>
#include <IGESSolid_SolidOfLinearExtrusion.hxx>
#include <IGESSolid_Ellipsoid.hxx>
#include <IGESSolid_BooleanTree.hxx>
#include <IGESSolid_SelectedComponent.hxx>
#include <IGESSolid_SolidAssembly.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <IGESSolid_PlaneSurface.hxx>
#include <IGESSolid_CylindricalSurface.hxx>
#include <IGESSolid_ConicalSurface.hxx>
#include <IGESSolid_SphericalSurface.hxx>
#include <IGESSolid_ToroidalSurface.hxx>
#include <IGESSolid_SolidInstance.hxx>
#include <IGESSolid_VertexList.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <IGESSolid_Loop.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Shell.hxx>
#include <IGESSolid_ToolBlock.hxx>
#include <IGESSolid_ToolRightAngularWedge.hxx>
#include <IGESSolid_ToolCylinder.hxx>
#include <IGESSolid_ToolConeFrustum.hxx>
#include <IGESSolid_ToolSphere.hxx>
#include <IGESSolid_ToolTorus.hxx>
#include <IGESSolid_ToolSolidOfRevolution.hxx>
#include <IGESSolid_ToolSolidOfLinearExtrusion.hxx>
#include <IGESSolid_ToolEllipsoid.hxx>
#include <IGESSolid_ToolBooleanTree.hxx>
#include <IGESSolid_ToolSelectedComponent.hxx>
#include <IGESSolid_ToolSolidAssembly.hxx>
#include <IGESSolid_ToolManifoldSolid.hxx>
#include <IGESSolid_ToolPlaneSurface.hxx>
#include <IGESSolid_ToolCylindricalSurface.hxx>
#include <IGESSolid_ToolConicalSurface.hxx>
#include <IGESSolid_ToolSphericalSurface.hxx>
#include <IGESSolid_ToolToroidalSurface.hxx>
#include <IGESSolid_ToolSolidInstance.hxx>
#include <IGESSolid_ToolVertexList.hxx>
#include <IGESSolid_ToolEdgeList.hxx>
#include <IGESSolid_ToolLoop.hxx>
#include <IGESSolid_ToolFace.hxx>
#include <IGESSolid_ToolShell.hxx>
#include <IGESSolid_ReadWriteModule.hxx>
#include <IGESSolid_GeneralModule.hxx>
#include <IGESSolid_SpecificModule.hxx>
#include <IGESSolid_TopoBuilder.hxx>
#include <IGESSolid.hxx>

void bind_IGESSolid(py::module &mod){

py::class_<IGESSolid, std::unique_ptr<IGESSolid>> cls_IGESSolid(mod, "IGESSolid", "This package consists of B-Rep and CSG Solid entities");

// Constructors

// Fields

// Methods
// cls_IGESSolid.def_static("operator new_", (void * (*)(size_t)) &IGESSolid::operator new, "None", py::arg("theSize"));
// cls_IGESSolid.def_static("operator delete_", (void (*)(void *)) &IGESSolid::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid.def_static("Init_", (void (*)()) &IGESSolid::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESSolid.def_static("Protocol_", (opencascade::handle<IGESSolid_Protocol> (*)()) &IGESSolid::Protocol, "Returns the Protocol for this Package");

// Enums

}