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

void bind_BVH_Vec2i(py::module &);
void bind_BVH_Vec3i(py::module &);
void bind_BVH_Vec4i(py::module &);
void bind_BVH_Array2i(py::module &);
void bind_BVH_Array3i(py::module &);
void bind_BVH_Array4i(py::module &);
void bind_BVH_Vec2f(py::module &);
void bind_BVH_Vec3f(py::module &);
void bind_BVH_Vec4f(py::module &);
void bind_BVH_Array2f(py::module &);
void bind_BVH_Array3f(py::module &);
void bind_BVH_Array4f(py::module &);
void bind_BVH_Vec2d(py::module &);
void bind_BVH_Vec3d(py::module &);
void bind_BVH_Vec4d(py::module &);
void bind_BVH_Array2d(py::module &);
void bind_BVH_Array3d(py::module &);
void bind_BVH_Array4d(py::module &);
void bind_BVH_Mat4f(py::module &);
void bind_BVH_Mat4d(py::module &);
void bind_BVH_TreeBaseTransient(py::module &);
void bind_BVH_QuadTree(py::module &);
void bind_BVH_BinaryTree(py::module &);
void bind_BVH_BuilderTransient(py::module &);
void bind_BVH_Properties(py::module &);
void bind_BVH_ObjectTransient(py::module &);
void bind_BVH_BuildQueue(py::module &);
void bind_BVH_BuildTool(py::module &);
void bind_BVH_BuildThread(py::module &);
void bind_BVH_PrimitiveSet3d(py::module &);
void bind_BVH_EncodedLink(py::module &);

PYBIND11_MODULE(BVH, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.OSD");

bind_BVH_Vec2i(mod);
bind_BVH_Vec3i(mod);
bind_BVH_Vec4i(mod);
bind_BVH_Array2i(mod);
bind_BVH_Array3i(mod);
bind_BVH_Array4i(mod);
bind_BVH_Vec2f(mod);
bind_BVH_Vec3f(mod);
bind_BVH_Vec4f(mod);
bind_BVH_Array2f(mod);
bind_BVH_Array3f(mod);
bind_BVH_Array4f(mod);
bind_BVH_Vec2d(mod);
bind_BVH_Vec3d(mod);
bind_BVH_Vec4d(mod);
bind_BVH_Array2d(mod);
bind_BVH_Array3d(mod);
bind_BVH_Array4d(mod);
bind_BVH_Mat4f(mod);
bind_BVH_Mat4d(mod);
bind_BVH_TreeBaseTransient(mod);
bind_BVH_QuadTree(mod);
bind_BVH_BinaryTree(mod);
bind_BVH_BuilderTransient(mod);
bind_BVH_Properties(mod);
bind_BVH_ObjectTransient(mod);
bind_BVH_BuildQueue(mod);
bind_BVH_BuildTool(mod);
bind_BVH_BuildThread(mod);
bind_BVH_PrimitiveSet3d(mod);
bind_BVH_EncodedLink(mod);

}
