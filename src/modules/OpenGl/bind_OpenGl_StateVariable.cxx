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
#include <OpenGl_ShaderProgram.hxx>

void bind_OpenGl_StateVariable(py::module &mod){

py::enum_<OpenGl_StateVariable>(mod, "OpenGl_StateVariable", "The enumeration of OCCT-specific OpenGL/GLSL variables.")
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX)
	.value("OpenGl_OCC_PROJECTION_MATRIX", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_INVERSE)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_CLIP_PLANE_EQUATIONS", OpenGl_StateVariable::OpenGl_OCC_CLIP_PLANE_EQUATIONS)
	.value("OpenGl_OCC_CLIP_PLANE_COUNT", OpenGl_StateVariable::OpenGl_OCC_CLIP_PLANE_COUNT)
	.value("OpenGl_OCC_LIGHT_SOURCE_COUNT", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_COUNT)
	.value("OpenGl_OCC_LIGHT_SOURCE_TYPES", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_TYPES)
	.value("OpenGl_OCC_LIGHT_SOURCE_PARAMS", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_PARAMS)
	.value("OpenGl_OCC_LIGHT_AMBIENT", OpenGl_StateVariable::OpenGl_OCC_LIGHT_AMBIENT)
	.value("OpenGl_OCCT_TEXTURE_ENABLE", OpenGl_StateVariable::OpenGl_OCCT_TEXTURE_ENABLE)
	.value("OpenGl_OCCT_DISTINGUISH_MODE", OpenGl_StateVariable::OpenGl_OCCT_DISTINGUISH_MODE)
	.value("OpenGl_OCCT_FRONT_MATERIAL", OpenGl_StateVariable::OpenGl_OCCT_FRONT_MATERIAL)
	.value("OpenGl_OCCT_BACK_MATERIAL", OpenGl_StateVariable::OpenGl_OCCT_BACK_MATERIAL)
	.value("OpenGl_OCCT_ALPHA_CUTOFF", OpenGl_StateVariable::OpenGl_OCCT_ALPHA_CUTOFF)
	.value("OpenGl_OCCT_COLOR", OpenGl_StateVariable::OpenGl_OCCT_COLOR)
	.value("OpenGl_OCCT_OIT_OUTPUT", OpenGl_StateVariable::OpenGl_OCCT_OIT_OUTPUT)
	.value("OpenGl_OCCT_OIT_DEPTH_FACTOR", OpenGl_StateVariable::OpenGl_OCCT_OIT_DEPTH_FACTOR)
	.value("OpenGl_OCCT_TEXTURE_TRSF2D", OpenGl_StateVariable::OpenGl_OCCT_TEXTURE_TRSF2D)
	.value("OpenGl_OCCT_POINT_SIZE", OpenGl_StateVariable::OpenGl_OCCT_POINT_SIZE)
	.value("OpenGl_OCCT_NUMBER_OF_STATE_VARIABLES", OpenGl_StateVariable::OpenGl_OCCT_NUMBER_OF_STATE_VARIABLES)
	.export_values();

py::enum_<OpenGl_UniformStateType>(mod, "OpenGl_UniformStateType", "Defines types of uniform state variables.")
	.value("OpenGl_LIGHT_SOURCES_STATE", OpenGl_UniformStateType::OpenGl_LIGHT_SOURCES_STATE)
	.value("OpenGl_CLIP_PLANES_STATE", OpenGl_UniformStateType::OpenGl_CLIP_PLANES_STATE)
	.value("OpenGl_MODEL_WORLD_STATE", OpenGl_UniformStateType::OpenGl_MODEL_WORLD_STATE)
	.value("OpenGl_WORLD_VIEW_STATE", OpenGl_UniformStateType::OpenGl_WORLD_VIEW_STATE)
	.value("OpenGl_PROJECTION_STATE", OpenGl_UniformStateType::OpenGl_PROJECTION_STATE)
	.value("OpenGl_MATERIAL_STATE", OpenGl_UniformStateType::OpenGl_MATERIAL_STATE)
	.value("OpenGl_SURF_DETAIL_STATE", OpenGl_UniformStateType::OpenGl_SURF_DETAIL_STATE)
	.value("OpenGL_OIT_STATE", OpenGl_UniformStateType::OpenGL_OIT_STATE)
	.value("OpenGl_UniformStateType_NB", OpenGl_UniformStateType::OpenGl_UniformStateType_NB)
	.export_values();


}