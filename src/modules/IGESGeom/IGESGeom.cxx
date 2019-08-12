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

void bind_IGESGeom(py::module &);
void bind_IGESGeom_Boundary(py::module &);
void bind_IGESGeom_Array1OfBoundary(py::module &);
void bind_IGESGeom_CurveOnSurface(py::module &);
void bind_IGESGeom_Array1OfCurveOnSurface(py::module &);
void bind_IGESGeom_TransformationMatrix(py::module &);
void bind_IGESGeom_Array1OfTransformationMatrix(py::module &);
void bind_IGESGeom_HArray1OfBoundary(py::module &);
void bind_IGESGeom_BoundedSurface(py::module &);
void bind_IGESGeom_BSplineCurve(py::module &);
void bind_IGESGeom_BSplineSurface(py::module &);
void bind_IGESGeom_CircularArc(py::module &);
void bind_IGESGeom_CompositeCurve(py::module &);
void bind_IGESGeom_ConicArc(py::module &);
void bind_IGESGeom_CopiousData(py::module &);
void bind_IGESGeom_Direction(py::module &);
void bind_IGESGeom_Flash(py::module &);
void bind_IGESGeom_GeneralModule(py::module &);
void bind_IGESGeom_HArray1OfCurveOnSurface(py::module &);
void bind_IGESGeom_HArray1OfTransformationMatrix(py::module &);
void bind_IGESGeom_Line(py::module &);
void bind_IGESGeom_OffsetCurve(py::module &);
void bind_IGESGeom_OffsetSurface(py::module &);
void bind_IGESGeom_Plane(py::module &);
void bind_IGESGeom_Point(py::module &);
void bind_IGESGeom_Protocol(py::module &);
void bind_IGESGeom_ReadWriteModule(py::module &);
void bind_IGESGeom_RuledSurface(py::module &);
void bind_IGESGeom_SpecificModule(py::module &);
void bind_IGESGeom_SplineCurve(py::module &);
void bind_IGESGeom_SplineSurface(py::module &);
void bind_IGESGeom_SurfaceOfRevolution(py::module &);
void bind_IGESGeom_TabulatedCylinder(py::module &);
void bind_IGESGeom_ToolBoundary(py::module &);
void bind_IGESGeom_ToolBoundedSurface(py::module &);
void bind_IGESGeom_ToolBSplineCurve(py::module &);
void bind_IGESGeom_ToolBSplineSurface(py::module &);
void bind_IGESGeom_ToolCircularArc(py::module &);
void bind_IGESGeom_ToolCompositeCurve(py::module &);
void bind_IGESGeom_ToolConicArc(py::module &);
void bind_IGESGeom_ToolCopiousData(py::module &);
void bind_IGESGeom_ToolCurveOnSurface(py::module &);
void bind_IGESGeom_ToolDirection(py::module &);
void bind_IGESGeom_ToolFlash(py::module &);
void bind_IGESGeom_ToolLine(py::module &);
void bind_IGESGeom_ToolOffsetCurve(py::module &);
void bind_IGESGeom_ToolOffsetSurface(py::module &);
void bind_IGESGeom_ToolPlane(py::module &);
void bind_IGESGeom_ToolPoint(py::module &);
void bind_IGESGeom_ToolRuledSurface(py::module &);
void bind_IGESGeom_ToolSplineCurve(py::module &);
void bind_IGESGeom_ToolSplineSurface(py::module &);
void bind_IGESGeom_ToolSurfaceOfRevolution(py::module &);
void bind_IGESGeom_ToolTabulatedCylinder(py::module &);
void bind_IGESGeom_ToolTransformationMatrix(py::module &);
void bind_IGESGeom_ToolTrimmedSurface(py::module &);
void bind_IGESGeom_TrimmedSurface(py::module &);

PYBIND11_MODULE(IGESGeom, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");

bind_IGESGeom(mod);
bind_IGESGeom_Boundary(mod);
bind_IGESGeom_Array1OfBoundary(mod);
bind_IGESGeom_CurveOnSurface(mod);
bind_IGESGeom_Array1OfCurveOnSurface(mod);
bind_IGESGeom_TransformationMatrix(mod);
bind_IGESGeom_Array1OfTransformationMatrix(mod);
bind_IGESGeom_HArray1OfBoundary(mod);
bind_IGESGeom_BoundedSurface(mod);
bind_IGESGeom_BSplineCurve(mod);
bind_IGESGeom_BSplineSurface(mod);
bind_IGESGeom_CircularArc(mod);
bind_IGESGeom_CompositeCurve(mod);
bind_IGESGeom_ConicArc(mod);
bind_IGESGeom_CopiousData(mod);
bind_IGESGeom_Direction(mod);
bind_IGESGeom_Flash(mod);
bind_IGESGeom_GeneralModule(mod);
bind_IGESGeom_HArray1OfCurveOnSurface(mod);
bind_IGESGeom_HArray1OfTransformationMatrix(mod);
bind_IGESGeom_Line(mod);
bind_IGESGeom_OffsetCurve(mod);
bind_IGESGeom_OffsetSurface(mod);
bind_IGESGeom_Plane(mod);
bind_IGESGeom_Point(mod);
bind_IGESGeom_Protocol(mod);
bind_IGESGeom_ReadWriteModule(mod);
bind_IGESGeom_RuledSurface(mod);
bind_IGESGeom_SpecificModule(mod);
bind_IGESGeom_SplineCurve(mod);
bind_IGESGeom_SplineSurface(mod);
bind_IGESGeom_SurfaceOfRevolution(mod);
bind_IGESGeom_TabulatedCylinder(mod);
bind_IGESGeom_ToolBoundary(mod);
bind_IGESGeom_ToolBoundedSurface(mod);
bind_IGESGeom_ToolBSplineCurve(mod);
bind_IGESGeom_ToolBSplineSurface(mod);
bind_IGESGeom_ToolCircularArc(mod);
bind_IGESGeom_ToolCompositeCurve(mod);
bind_IGESGeom_ToolConicArc(mod);
bind_IGESGeom_ToolCopiousData(mod);
bind_IGESGeom_ToolCurveOnSurface(mod);
bind_IGESGeom_ToolDirection(mod);
bind_IGESGeom_ToolFlash(mod);
bind_IGESGeom_ToolLine(mod);
bind_IGESGeom_ToolOffsetCurve(mod);
bind_IGESGeom_ToolOffsetSurface(mod);
bind_IGESGeom_ToolPlane(mod);
bind_IGESGeom_ToolPoint(mod);
bind_IGESGeom_ToolRuledSurface(mod);
bind_IGESGeom_ToolSplineCurve(mod);
bind_IGESGeom_ToolSplineSurface(mod);
bind_IGESGeom_ToolSurfaceOfRevolution(mod);
bind_IGESGeom_ToolTabulatedCylinder(mod);
bind_IGESGeom_ToolTransformationMatrix(mod);
bind_IGESGeom_ToolTrimmedSurface(mod);
bind_IGESGeom_TrimmedSurface(mod);

}
