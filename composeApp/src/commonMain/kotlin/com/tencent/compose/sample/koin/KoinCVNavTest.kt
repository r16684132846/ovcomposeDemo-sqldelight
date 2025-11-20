package com.tencent.compose.sample.koin

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items

import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.automirrored.filled.ArrowBack
import androidx.compose.runtime.Composable
import androidx.compose.ui.*
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import androidx.navigation.NavType
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.navigation.navArgument
import org.koin.compose.koinInject

@Composable
fun AppNavigation() {
    val navController = rememberNavController()

    NavHost(
        navController = navController,
        startDestination = "home"
    ) {
        composable("home") {
            HomeScreen(navController = navController)
        }

        composable(
            "detail/{userId}",
            arguments = listOf(
                navArgument("userId") {
                    type = NavType.IntType
                }
            )
        ) {
            DetailScreen(navController = navController)
        }
    }
}


@Composable
fun HomeScreen(
    navController: NavHostController
) {
    val viewModel = koinInject<UserViewModel>()

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
    ) {
        Text(
            text = "用户列表",
            style = MaterialTheme.typography.h2
        )

        Spacer(modifier = Modifier.height(16.dp))

        LazyColumn {
            items(viewModel.getAllUsers()) { user ->
                UserItem(
                    user = user,
                    onClick = {
                        viewModel.setCurrentUserID(user.id)
                        navController.navigate("detail/${user.id}")
                    }
                )
                Spacer(modifier = Modifier.height(8.dp))
            }
        }
    }
}

@Composable
fun UserItem(
    user: User,
    onClick: () -> Unit
) {
    Column(
        modifier = Modifier.fillMaxWidth()
            .clickable {
                onClick()
            }
    ) {
        Column(
            modifier = Modifier.padding(16.dp)
        ) {
            Text(
                text = user.name,
                style = MaterialTheme.typography.h3
            )
            Text(
                text = user.email,
                style = MaterialTheme.typography.h3
            )
        }
    }
}

@Composable
fun DetailScreen(
    navController: NavHostController
) {
    // 关键：使用 koinInject 获取带参数的 ViewModel
    val viewModel = koinInject<UserViewModel>()


    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("用户详情") },
                navigationIcon = {
                    IconButton(onClick = { navController.popBackStack() }) {
                        Icon(Icons.AutoMirrored.Filled.ArrowBack, contentDescription = "返回")
                    }
                }
            )
        }
    ) { paddingValues ->
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(paddingValues)
                .padding(16.dp)
        ) {
            UserDetailCard(viewModel)
        }
    }
}

@Composable
fun UserDetailCard(viewModel: UserViewModel) {
    val user = viewModel.getCurrentUser()
    Card(
        modifier = Modifier.fillMaxWidth()
    ) {
        Column(
            modifier = Modifier.padding(16.dp)
        ) {
            Text(
                text = user?.name ?: "用户不存在",
                style = MaterialTheme.typography.h2,
                color = MaterialTheme.colors.onPrimary
            )

            Spacer(modifier = Modifier.height(16.dp))

            Text(
                text = user?.id ?.toString() ?: "",
                style = MaterialTheme.typography.body2
            )

            Spacer(modifier = Modifier.height(8.dp))

            Text(
                text = user?.email ?: "",
                style = MaterialTheme.typography.h3
            )
        }
    }
}
