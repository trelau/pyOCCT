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

void bind_IGESSolid(py::module &);
void bind_IGESSolid_Loop(py::module &);
void bind_IGESSolid_Array1OfLoop(py::module &);
void bind_IGESSolid_HArray1OfLoop(py::module &);
void bind_IGESSolid_Face(py::module &);
void bind_IGESSolid_Array1OfFace(py::module &);
void bind_IGESSolid_HArray1OfFace(py::module &);
void bind_IGESSolid_Shell(py::module &);
void bind_IGESSolid_Array1OfShell(py::module &);
void bind_IGESSolid_VertexList(py::module &);
void bind_IGESSolid_Array1OfVertexList(py::module &);
void bind_IGESSolid_Block(py::module &);
void bind_IGESSolid_BooleanTree(py::module &);
void bind_IGESSolid_ConeFrustum(py::module &);
void bind_IGESSolid_ConicalSurface(py::module &);
void bind_IGESSolid_Cylinder(py::module &);
void bind_IGESSolid_CylindricalSurface(py::module &);
void bind_IGESSolid_HArray1OfVertexList(py::module &);
void bind_IGESSolid_EdgeList(py::module &);
void bind_IGESSolid_Ellipsoid(py::module &);
void bind_IGESSolid_GeneralModule(py::module &);
void bind_IGESSolid_HArray1OfShell(py::module &);
void bind_IGESSolid_ManifoldSolid(py::module &);
void bind_IGESSolid_PlaneSurface(py::module &);
void bind_IGESSolid_Protocol(py::module &);
void bind_IGESSolid_ReadWriteModule(py::module &);
void bind_IGESSolid_RightAngularWedge(py::module &);
void bind_IGESSolid_SelectedComponent(py::module &);
void bind_IGESSolid_SolidAssembly(py::module &);
void bind_IGESSolid_SolidInstance(py::module &);
void bind_IGESSolid_SolidOfLinearExtrusion(py::module &);
void bind_IGESSolid_SolidOfRevolution(py::module &);
void bind_IGESSolid_SpecificModule(py::module &);
void bind_IGESSolid_Sphere(py::module &);
void bind_IGESSolid_SphericalSurface(py::module &);
void bind_IGESSolid_ToolBlock(py::module &);
void bind_IGESSolid_ToolBooleanTree(py::module &);
void bind_IGESSolid_ToolConeFrustum(py::module &);
void bind_IGESSolid_ToolConicalSurface(py::module &);
void bind_IGESSolid_ToolCylinder(py::module &);
void bind_IGESSolid_ToolCylindricalSurface(py::module &);
void bind_IGESSolid_ToolEdgeList(py::module &);
void bind_IGESSolid_ToolEllipsoid(py::module &);
void bind_IGESSolid_ToolFace(py::module &);
void bind_IGESSolid_ToolLoop(py::module &);
void bind_IGESSolid_ToolManifoldSolid(py::module &);
void bind_IGESSolid_ToolPlaneSurface(py::module &);
void bind_IGESSolid_ToolRightAngularWedge(py::module &);
void bind_IGESSolid_ToolSelectedComponent(py::module &);
void bind_IGESSolid_ToolShell(py::module &);
void bind_IGESSolid_ToolSolidAssembly(py::module &);
void bind_IGESSolid_ToolSolidInstance(py::module &);
void bind_IGESSolid_ToolSolidOfLinearExtrusion(py::module &);
void bind_IGESSolid_ToolSolidOfRevolution(py::module &);
void bind_IGESSolid_ToolSphere(py::module &);
void bind_IGESSolid_ToolSphericalSurface(py::module &);
void bind_IGESSolid_ToolToroidalSurface(py::module &);
void bind_IGESSolid_ToolTorus(py::module &);
void bind_IGESSolid_ToolVertexList(py::module &);
void bind_IGESSolid_TopoBuilder(py::module &);
void bind_IGESSolid_ToroidalSurface(py::module &);
void bind_IGESSolid_Torus(py::module &);

PYBIND11_MODULE(IGESSolid, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");

bind_IGESSolid(mod);
bind_IGESSolid_Loop(mod);
bind_IGESSolid_Array1OfLoop(mod);
bind_IGESSolid_HArray1OfLoop(mod);
bind_IGESSolid_Face(mod);
bind_IGESSolid_Array1OfFace(mod);
bind_IGESSolid_HArray1OfFace(mod);
bind_IGESSolid_Shell(mod);
bind_IGESSolid_Array1OfShell(mod);
bind_IGESSolid_VertexList(mod);
bind_IGESSolid_Array1OfVertexList(mod);
bind_IGESSolid_Block(mod);
bind_IGESSolid_BooleanTree(mod);
bind_IGESSolid_ConeFrustum(mod);
bind_IGESSolid_ConicalSurface(mod);
bind_IGESSolid_Cylinder(mod);
bind_IGESSolid_CylindricalSurface(mod);
bind_IGESSolid_HArray1OfVertexList(mod);
bind_IGESSolid_EdgeList(mod);
bind_IGESSolid_Ellipsoid(mod);
bind_IGESSolid_GeneralModule(mod);
bind_IGESSolid_HArray1OfShell(mod);
bind_IGESSolid_ManifoldSolid(mod);
bind_IGESSolid_PlaneSurface(mod);
bind_IGESSolid_Protocol(mod);
bind_IGESSolid_ReadWriteModule(mod);
bind_IGESSolid_RightAngularWedge(mod);
bind_IGESSolid_SelectedComponent(mod);
bind_IGESSolid_SolidAssembly(mod);
bind_IGESSolid_SolidInstance(mod);
bind_IGESSolid_SolidOfLinearExtrusion(mod);
bind_IGESSolid_SolidOfRevolution(mod);
bind_IGESSolid_SpecificModule(mod);
bind_IGESSolid_Sphere(mod);
bind_IGESSolid_SphericalSurface(mod);
bind_IGESSolid_ToolBlock(mod);
bind_IGESSolid_ToolBooleanTree(mod);
bind_IGESSolid_ToolConeFrustum(mod);
bind_IGESSolid_ToolConicalSurface(mod);
bind_IGESSolid_ToolCylinder(mod);
bind_IGESSolid_ToolCylindricalSurface(mod);
bind_IGESSolid_ToolEdgeList(mod);
bind_IGESSolid_ToolEllipsoid(mod);
bind_IGESSolid_ToolFace(mod);
bind_IGESSolid_ToolLoop(mod);
bind_IGESSolid_ToolManifoldSolid(mod);
bind_IGESSolid_ToolPlaneSurface(mod);
bind_IGESSolid_ToolRightAngularWedge(mod);
bind_IGESSolid_ToolSelectedComponent(mod);
bind_IGESSolid_ToolShell(mod);
bind_IGESSolid_ToolSolidAssembly(mod);
bind_IGESSolid_ToolSolidInstance(mod);
bind_IGESSolid_ToolSolidOfLinearExtrusion(mod);
bind_IGESSolid_ToolSolidOfRevolution(mod);
bind_IGESSolid_ToolSphere(mod);
bind_IGESSolid_ToolSphericalSurface(mod);
bind_IGESSolid_ToolToroidalSurface(mod);
bind_IGESSolid_ToolTorus(mod);
bind_IGESSolid_ToolVertexList(mod);
bind_IGESSolid_TopoBuilder(mod);
bind_IGESSolid_ToroidalSurface(mod);
bind_IGESSolid_Torus(mod);

}
